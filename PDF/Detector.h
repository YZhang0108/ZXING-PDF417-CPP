#ifndef __DETECTOR_PDF417_H__
#define __DETECTOR_PDF417_H__

/*
 *  Detector.h
 *  zxing
 *
 *  Copyright 2010 ZXing authors All rights reserved.
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
 */

//#include <zxing/common/Point.h>
//#include <zxing/common/DetectorResult.h>
//#include <zxing/NotFoundException.h>
//#include <zxing/BinaryBitmap.h>
//#include <zxing/DecodeHints.h>

#include "common/Point.h"
#include "common/DetectorResult.h"
#include "NotFoundException.h"
#include "BinaryBitmap.h"
#include "DecodeHints.h"



namespace zxing {
namespace pdf417 {
namespace detector {

class Detector {
protected:
    static const int INTEGER_MATH_SHIFT = 8;
    static const int PATTERN_MATCH_RESULT_SCALE_FACTOR = 1 << INTEGER_MATH_SHIFT;
    static const int MAX_AVG_VARIANCE;
    static const int MAX_INDIVIDUAL_VARIANCE;

    static const int START_PATTERN[];
    static const int START_PATTERN_LENGTH;
    static const int START_PATTERN_REVERSE[];
    static const int START_PATTERN_REVERSE_LENGTH;
    static const int STOP_PATTERN[];
    static const int STOP_PATTERN_LENGTH;
    static const int STOP_PATTERN_REVERSE[];
    static const int STOP_PATTERN_REVERSE_LENGTH;
//  BinaryBitmap image_;
 Ref<BinaryBitmap> image_;
  
   ArrayRef< Ref<ResultPoint> > findVertices(Ref<BitMatrix> matrix, int rowStep);
   ArrayRef< Ref<ResultPoint> > findVertices180(Ref<BitMatrix> matrix, int rowStep);

   ArrayRef<int> findGuardPattern(Ref<BitMatrix> matrix,
                                        int column,
                                        int row,
                                        int width,
                                        bool whiteFirst,
                                        const int pattern[],
                                        int patternSize,
                                        ArrayRef<int>& counters);
   int patternMatchVariance(ArrayRef<int>& counters, const int pattern[],
                                  int maxIndividualVariance);

   void correctVertices(Ref<BitMatrix> matrix,
                              ArrayRef< Ref<ResultPoint> >& vertices,
                              bool upsideDown);
   void findWideBarTopBottom(Ref<BitMatrix> matrix,
                                   ArrayRef< Ref<ResultPoint> >& vertices,
                                   int offsetVertice,
                                   int startWideBar,
                                   int lenWideBar,
                                   int lenPattern,
                                   int nIncrement);
   void findCrossingPoint(ArrayRef< Ref<ResultPoint> >& vertices,
                                int idxResult,
                                int idxLineA1,int idxLineA2,
                                int idxLineB1,int idxLineB2,
                                Ref<BitMatrix>& matrix);
   Point intersection(Line a, Line b);
   float computeModuleWidth(ArrayRef< Ref<ResultPoint> >& vertices);
   int computeDimension(Ref<ResultPoint> const& topLeft,
                              Ref<ResultPoint> const& topRight,
                              Ref<ResultPoint> const& bottomLeft,
                              Ref<ResultPoint> const& bottomRight,
                              float moduleWidth);
  int computeYDimension(Ref<ResultPoint> const& topLeft,
                        Ref<ResultPoint> const& topRight,
                        Ref<ResultPoint> const& bottomLeft,
                        Ref<ResultPoint> const& bottomRight,
                        float moduleWidth);

  Ref<BitMatrix> sampleLines(ArrayRef< Ref<ResultPoint> > const& vertices, int dimensionY, int dimension);

public:
  Detector(Ref<BinaryBitmap> image);
//    Detector(BinaryBitmap image);

    Ref<BinaryBitmap> getImage();
  Ref<DetectorResult> detect();
  Ref<DetectorResult> detect(DecodeHints const& hints);
  Ref<DetectorResult> PdfDetector(Ref<BinaryBitmap> image, DecodeHints hints);
};

}
}
}

#endif // __DETECTOR_PDF417_H__
