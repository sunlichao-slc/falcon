//
// Created by wuyuncheng on 14/11/20.
//

#include <falcon/utils/io_util.h>
#include <falcon/utils/pb_converter/phe_keys_converter.h>

#include <vector>

#include <gtest/gtest.h>

TEST(IO_Util, ReadWriteData) {
  // create dummy data
  std::vector< std::vector<double> > write_data;
  for (int i = 0; i < 2; i++) {
    std::vector<double> row;
    for (int j = 0; j < 3; j++) {
      row.push_back(i*100 + j*10 + 0.5);
    }
    write_data.push_back(row);
  }
  // write data to file
  std::string file_name = "test_io_util_data.txt";
  write_dataset_to_file(write_data, file_name);

  // read data and compare
  std::vector< std::vector<double> > read_data = read_dataset(file_name);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(write_data[i][j], read_data[i][j]);
    }
  }
}

TEST(IO_Util, ReadWriteKeys) {
// generate phe keys
  hcs_random* phe_random = hcs_init_random();
  djcs_t_public_key* phe_pub_key = djcs_t_init_public_key();
  djcs_t_private_key* phe_priv_key = djcs_t_init_private_key();
  djcs_t_auth_server** phe_auth_server = (djcs_t_auth_server **) malloc (3 * sizeof(djcs_t_auth_server *));
  mpz_t* si = (mpz_t *) malloc (3 * sizeof(mpz_t));
  djcs_t_generate_key_pair(phe_pub_key, phe_priv_key, phe_random, 1, 1024, 3, 3);
  mpz_t* coeff = djcs_t_init_polynomial(phe_priv_key, phe_random);
  for (int i = 0; i < 3; i++) {
    mpz_init(si[i]);
    djcs_t_compute_polynomial(phe_priv_key, coeff, si[i], i);
    phe_auth_server[i] = djcs_t_init_auth_server();
    djcs_t_set_auth_server(phe_auth_server[i], si[i], i);
  }

  // test serialization and deserialization
  for(int i = 0; i < 3; i++) {
    std::string write_message;
    serialize_phe_keys(phe_pub_key, phe_auth_server[i], write_message);

    std::string key_file_name = "test_key_file" + std::to_string(i) + ".pem";
    write_key_to_file(write_message, key_file_name);

    std::string read_message = read_key_file(key_file_name);
    djcs_t_public_key* deserialized_phe_pub_key = djcs_t_init_public_key();
    djcs_t_auth_server* deserialized_phe_auth_server = djcs_t_init_auth_server();
    deserialize_phe_keys(deserialized_phe_pub_key, deserialized_phe_auth_server, read_message);

    EXPECT_EQ(phe_pub_key->s, deserialized_phe_pub_key->s);
    EXPECT_EQ(phe_pub_key->l, deserialized_phe_pub_key->l);
    EXPECT_EQ(phe_pub_key->w, deserialized_phe_pub_key->w);
    EXPECT_EQ(0, mpz_cmp(phe_pub_key->g, deserialized_phe_pub_key->g));
    EXPECT_EQ(0, mpz_cmp(phe_pub_key->delta, deserialized_phe_pub_key->delta));
    for (int j = 0; j < phe_pub_key->s + 1; j++) {
      EXPECT_EQ(0, mpz_cmp(phe_pub_key->n[j], deserialized_phe_pub_key->n[j]));
    }
    EXPECT_EQ(0, mpz_cmp(phe_auth_server[i]->si, deserialized_phe_auth_server->si));
    EXPECT_EQ(phe_auth_server[i]->i, deserialized_phe_auth_server->i);

    djcs_t_free_public_key(deserialized_phe_pub_key);
    djcs_t_free_auth_server(deserialized_phe_auth_server);
  }

  // free memory
  hcs_free_random(phe_random);
  djcs_t_free_public_key(phe_pub_key);
  djcs_t_free_private_key(phe_priv_key);
  djcs_t_free_polynomial(phe_priv_key, coeff);
  for (int i = 0; i < 3; i++) {
    mpz_clear(si[i]);
    djcs_t_free_auth_server(phe_auth_server[i]);
  }
  free(si);
  free(phe_auth_server);
}