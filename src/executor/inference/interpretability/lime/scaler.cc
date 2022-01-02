//
// Created by root on 12/22/21.
//

#include <falcon/inference/interpretability/lime/scaler.h>

#include <algorithm>
#include <complex>

StandardScaler::StandardScaler(bool m_with_mean, bool m_with_std) {
  with_mean = m_with_mean;
  with_std = with_std;
}

StandardScaler::~StandardScaler() = default;

void StandardScaler::fit(std::vector<std::vector<double>> train_data, std::vector<double> train_labels) {
  feature_num = (int) train_data[0].size();
  int n_sample = (int) train_data.size();
  scale.reserve(feature_num);
  mean.reserve(feature_num);
  variance.reserve(feature_num);
  // TODO: check when with_mean = False, if this is correct
  if (!with_mean) {
    for (int f_id = 0; f_id < feature_num; f_id++) {
      mean.push_back(0.0);
    }
  } else {
    // compute the mean of each feature
    for (int f_id = 0; f_id < feature_num; f_id++) {
      double sum = 0.0;
      for (int s_id = 0; s_id < n_sample; s_id++) {
        sum += train_data[s_id][f_id];
      }
      double m = sum / n_sample;
      mean.push_back(m);
    }
  }
  // TODO check when with_std = False, if this is correct
  if (!with_std) {
    for (int f_id = 0; f_id < feature_num; f_id++) {
      variance.push_back(1.0);
      scale.push_back(1.0);
    }
  } else {
    // compute the variance of each feature
    for (int f_id = 0; f_id < feature_num; f_id++) {
      double var_sum = 0.0;
      for (int s_id = 0; s_id < n_sample; s_id++) {
        double err = train_data[s_id][f_id] - mean[f_id];
        var_sum += (err * err);
      }
      double var_avg = var_sum / n_sample;
      double scale_avg = std::sqrt(var_avg);
      variance.push_back(var_avg);
      scale.push_back(scale_avg);
    }
  }
}