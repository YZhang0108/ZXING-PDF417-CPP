// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-

#ifndef __ERROR_CORRECTION_PDF_H__
#define __ERROR_CORRECTION_PDF_H__
/*
 * Copyright 2012 ZXing authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * 2012-09-17 HFN translation from Java into C++
 */

#include "common/Counted.h"
#include "common/Array.h"
#include "common/DecoderResult.h"
#include "common/BitMatrix.h"
#include "ModulusGF.h"
#include "ModulusPoly.h"
#include "common/reedsolomon/ReedSolomonException.h"

namespace zxing {
namespace pdf417 {
namespace decoder {
namespace ec {


/**
 * <p>PDF417 error correction implementation.</p>
 *
 * <p>This <a href="http://en.wikipedia.org/wiki/Reed%E2%80%93Solomon_error_correction#Example">example</a>
 * is quite useful in understanding the algorithm.</p>
 *
 * @author Sean Owen
 * @see com.google.zxing.common.reedsolomon.ReedSolomonDecoder
 */
class ErrorCorrection: public Counted {

 private:
  ModulusGF &field_;

 public:
  ErrorCorrection();
  void decode(ArrayRef<int> received,
              int numECCodewords,
              ArrayRef<int> erasures);

 private:
  std::vector<Ref<ModulusPoly> > runEuclideanAlgorithm(Ref<ModulusPoly> a, Ref<ModulusPoly> b, int R);

  ArrayRef<int> findErrorLocations(Ref<ModulusPoly> errorLocator);
  ArrayRef<int> findErrorMagnitudes(Ref<ModulusPoly> errorEvaluator,
                                    Ref<ModulusPoly> errorLocator,
                                    ArrayRef<int> errorLocations);
};

}
}
}
}

#endif /* __ERROR_CORRECTION_PDF_H__ */
