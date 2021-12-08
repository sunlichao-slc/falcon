//
// Created by root on 11/11/21.
//

#include <falcon/common.h>
#include <falcon/algorithm/vertical/linear_model/linear_regression_model.h>
#include <falcon/utils/pb_converter/common_converter.h>
#include <falcon/operator/mpc/spdz_connector.h>
#include <falcon/utils/logger/logger.h>

#include <cmath>
#include <glog/logging.h>
#include <stack>
#include <Networking/ssl_sockets.h>
#include <iostream>

LinearRegressionModel::LinearRegressionModel() = default;

LinearRegressionModel::LinearRegressionModel(int m_weight_size) : LinearModel(m_weight_size) {}

LinearRegressionModel::~LinearRegressionModel() = default;

LinearRegressionModel::LinearRegressionModel(const LinearRegressionModel &linear_reg_model)
  : LinearModel(linear_reg_model) {}

LinearRegressionModel &LinearRegressionModel::operator=(const LinearRegressionModel &linear_reg_model) {
  LinearModel::operator=(linear_reg_model);
  return *this;
}

void LinearRegressionModel::predict(const Party &party,
                                    const std::vector<std::vector<double>> &predicted_samples,
                                    EncodedNumber *predicted_labels) const {
  // the prediction workflow of linear regression model is the process of
  // aggregating the encrypted weights and the batch samples via phe
  int cur_sample_size = (int) predicted_samples.size();
  auto** encoded_batch_samples = new EncodedNumber*[cur_sample_size];
  for (int i = 0; i < cur_sample_size; i++) {
    encoded_batch_samples[i] = new EncodedNumber[weight_size];
  }
  encode_samples(party, predicted_samples, encoded_batch_samples);

  int ciphertext_precision = 0 - local_weights[0].getter_exponent();
  int plaintext_precision = 0 - encoded_batch_samples[0][0].getter_exponent();
  int encrypted_batch_aggregation_precision = ciphertext_precision + plaintext_precision;
  log_info("ciphertext_precision = " + std::to_string(ciphertext_precision));
  log_info("plaintext_precision = " + std::to_string(plaintext_precision));
  log_info("batch_aggregation_precision = " + std::to_string(encrypted_batch_aggregation_precision));

  forward_computation(party,
                      cur_sample_size,
                      encoded_batch_samples,
                      encrypted_batch_aggregation_precision,
                      predicted_labels);

  log_info("predicted_labels[0] = " + std::to_string(abs(predicted_labels[0].getter_exponent())));

  for (int i = 0; i < cur_sample_size; i++) {
    delete[] encoded_batch_samples[i];
  }
  delete[] encoded_batch_samples;
}

void LinearRegressionModel::forward_computation(const Party &party,
                                                int cur_batch_size,
                                                EncodedNumber **encoded_batch_samples,
                                                int &encrypted_batch_aggregation_precision,
                                                EncodedNumber *predicted_labels) const {
  // homomorphic batch aggregation: for linear regression, the aggregation
  //  result is exactly the forward computation result
  // every party computes partial phe summation and sends to active party
  compute_batch_phe_aggregation(party,
                                cur_batch_size,
                                encoded_batch_samples,
                                encrypted_batch_aggregation_precision,
                                predicted_labels);
  log_info("[forward_computation]: forward computation success");
}