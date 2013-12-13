/*
 *   Copyright (c) 2010-2013, MIT Probabilistic Computing Project
 *
 *   Lead Developers: Dan Lovell and Jay Baxter
 *   Authors: Dan Lovell, Baxter Eaves, Jay Baxter, Vikash Mansinghka
 *   Research Leads: Vikash Mansinghka, Patrick Shafto
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */
#ifndef GUARD_doublyboundedroundedcontinuouscomponentmodel_h
#define GUARD_doublyboundedroundedcontinuouscomponentmodel_h

#include "RoundedContinuousComponentModel.h"
#include "numerics.h"
#include "utils.h"


class DoublyBoundedRoundedContinuousComponentModel : public RoundedContinuousComponentModel {
 public:
  DoublyBoundedRoundedContinuousComponentModel(CM_Hypers &in_hyper_hash, int LOWER_BOUND, int UPPER_BOUND) : RoundedContinuousComponentModel(in_hyper_hash), lower_bound((double) LOWER_BOUND), upper_bound((double) UPPER_BOUND) {};
  DoublyBoundedRoundedContinuousComponentModel(CM_Hypers &in_hyper_hash, int LOWER_BOUND, int UPPER_BOUND,
		  int COUNT, double SUM_X, double SUM_X_SQ) : RoundedContinuousComponentModel(in_hyper_hash, COUNT, SUM_X, SUM_X_SQ), lower_bound((double) LOWER_BOUND), upper_bound((double) UPPER_BOUND) {};
  virtual ~DoublyBoundedRoundedContinuousComponentModel() {};
  //
  // getters
  double get_draw(int random_seed) const;
  double get_draw_constrained(int random_seed, std::vector<double> constraints) const;
 private:
  double lower_bound;
  double upper_bound;
};

#endif // GUARD_doublyboundedroundedcontinuouscomponentmodel_h