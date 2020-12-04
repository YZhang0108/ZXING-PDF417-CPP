cmake_minimum_required(VERSION 3.10)
project(zxing_pdf417)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

add_executable(zxing_pdf417 main.cpp
        PDF/MatSource.cpp
        PDF/MatSource.h

        PDF/bigint/BigInteger.cc
        PDF/bigint/BigInteger.hh
        PDF/bigint/BigIntegerAlgorithms.cc
        PDF/bigint/BigIntegerAlgorithms.hh
        PDF/bigint/BigIntegerLibrary.hh
        PDF/bigint/BigIntegerUtils.cc
        PDF/bigint/BigIntegerUtils.hh
        PDF/bigint/BigUnsigned.cc
        PDF/bigint/BigUnsigned.hh
        PDF/bigint/BigUnsignedInABase.cc
        PDF/bigint/BigUnsignedInABase.hh
        PDF/bigint/NumberlikeArray.hh

        PDF/BarcodeFormat.cpp
        PDF/BarcodeFormat.h
        PDF/Binarizer.cpp
        PDF/Binarizer.h
        PDF/BinaryBitmap.cpp
        PDF/BinaryBitmap.h
        PDF/BitMatrixParser.h
        PDF/BitMatrixParser_pdf417.cpp
        PDF/ChecksumException.cpp
        PDF/ChecksumException.h
        PDF/DecodedBitStreamParser.h
        PDF/DecodedBitStreamParser_pdf417.cpp
        PDF/DecodeHints.cpp
        PDF/DecodeHints.h
        PDF/Decoder.h
        PDF/Decoder_pdf417.cpp
        PDF/Detector.h
        PDF/Detector_pdf417.cpp
        PDF/ErrorCorrection.cpp
        PDF/ErrorCorrection.h
        PDF/Exception.cpp
        PDF/Exception.h
        PDF/FormatException.cpp
        PDF/FormatException.h
        PDF/IllegalStateException.h
        PDF/InvertedLuminanceSource.cpp
        PDF/InvertedLuminanceSource.h
        PDF/LinesSampler.cpp
        PDF/LinesSampler.h
        PDF/LuminanceSource.cpp
        PDF/LuminanceSource.h
        PDF/ModulusGF.cpp
        PDF/ModulusGF.h
        PDF/ModulusPoly.cpp
        PDF/ModulusPoly.h
        PDF/MultiFormatReader.cpp
        PDF/MultiFormatReader.h
        PDF/NotFoundException.h
        PDF/PDF417Reader.cpp
        PDF/PDF417Reader.h
        PDF/Reader.cpp
        PDF/Reader.h
        PDF/ReaderException.h
        PDF/Result.cpp
        PDF/Result.h
        PDF/ResultIO.cpp
        PDF/ResultPoint.cpp
        PDF/ResultPoint.h
        PDF/ResultPointCallback.cpp
        PDF/ResultPointCallback.h
        PDF/ZXing.h

        PDF/common/Array.h
        PDF/common/BitArray.cpp
        PDF/common/BitArray.h
        PDF/common/BitArrayIO.cpp
        PDF/common/BitMatrix.cpp
        PDF/common/BitMatrix.h
        PDF/common/BitSource.cpp
        PDF/common/BitSource.h
        PDF/common/CharacterSetECI.cpp
        PDF/common/CharacterSetECI.h
        PDF/common/Counted.h
        PDF/common/DecoderResult.cpp
        PDF/common/DecoderResult.h
        PDF/common/DetectorResult.cpp
        PDF/common/DetectorResult.h
        PDF/common/GlobalHistogramBinarizer.cpp
        PDF/common/GlobalHistogramBinarizer.h
        PDF/common/GreyscaleLuminanceSource.cpp
        PDF/common/GreyscaleLuminanceSource.h
        PDF/common/GreyscaleRotatedLuminanceSource.cpp
        PDF/common/GreyscaleRotatedLuminanceSource.h
        PDF/common/GridSampler.cpp
        PDF/common/GridSampler.h
        PDF/common/HybridBinarizer.cpp
        PDF/common/HybridBinarizer.h
        PDF/common/IllegalArgumentException.cpp
        PDF/common/IllegalArgumentException.h
        PDF/common/PerspectiveTransform.cpp
        PDF/common/PerspectiveTransform.h
        PDF/common/Point.h
        PDF/common/Str.cpp
        PDF/common/Str.h
        PDF/common/StringUtils.cpp
        PDF/common/StringUtils.h

        PDF/common/reedsolomon/GenericGF.cpp
        PDF/common/reedsolomon/GenericGF.h
        PDF/common/reedsolomon/GenericGFPoly.cpp
        PDF/common/reedsolomon/GenericGFPoly.h
        PDF/common/reedsolomon/ReedSolomonDecoder.cpp
        PDF/common/reedsolomon/ReedSolomonDecoder.h
        PDF/common/reedsolomon/ReedSolomonException.cpp
        PDF/common/reedsolomon/ReedSolomonException.h

        PDF/common/detector/JavaMath.h
        PDF/common/detector/MathUtils.h
        PDF/common/detector/MonochromeRectangleDetector.cpp
        PDF/common/detector/MonochromeRectangleDetector.h
        PDF/common/detector/WhiteRectangleDetector.cpp
        PDF/common/detector/WhiteRectangleDetector.h

#        pdf417/PDFBarcodeMetadata.h
#        pdf417/PDFBarcodeValue.cpp
#        pdf417/PDFBarcodeValue.h
#        pdf417/PDFBoundingBox.cpp
#        pdf417/PDFBoundingBox.h
#        pdf417/PDFCodeword.h
#        pdf417/PDFCodewordDecoder.cpp
#        pdf417/PDFCodewordDecoder.h
#        pdf417/PDFCompaction.h
#        pdf417/PDFDecodedBitStreamParser.cpp
#        pdf417/PDFDecodedBitStreamParser.h
#        pdf417/PDFDecoderResultExtra.h
#        pdf417/PDFDetectionResult.cpp
#        pdf417/PDFDetectionResult.h
#        pdf417/PDFDetectionResultColumn.cpp
#        pdf417/PDFDetectionResultColumn.h
#        pdf417/PDFDetector.cpp
#        pdf417/PDFDetector.h
#        pdf417/PDFEncoder.cpp
#        pdf417/PDFEncoder.h
#        pdf417/PDFHighLevelEncoder.cpp
#        pdf417/PDFHighLevelEncoder.h
#        pdf417/PDFModulusGF.cpp
#        pdf417/PDFModulusGF.h
#        pdf417/PDFModulusPoly.cpp
#        pdf417/PDFModulusPoly.h
#        pdf417/PDFReader.cpp
#        pdf417/PDFReader.h
#        pdf417/PDFScanningDecoder.cpp
#        pdf417/PDFScanningDecoder.h
#        pdf417/PDFWriter.cpp
#        pdf417/PDFWriter.h
#        pdf417/ZXContainerAlgorithms.h
#        pdf417/TextEncoder.h
#        pdf417/ZXBigInteger.cpp
#        pdf417/DetectorResult.h
#        pdf417/BarcodeFormat.h
#        pdf417/HybridBinarizer.h
#        pdf417/Result.cpp
#        pdf417/TextDecoder.cpp
#        pdf417/DecodeStatus.cpp
#        pdf417/LuminanceSource.cpp
#        pdf417/MultiFormatWriter.cpp
#        pdf417/GlobalHistogramBinarizer.h
#        pdf417/ReedSolomonDecoder.h
#        pdf417/BitWrapperBinarizer.cpp
#        pdf417/ZXStrConvWorkaround.h
#        pdf417/CharacterSet.h
#        pdf417/GenericGF.h
#        pdf417/BitHacks.h
#        pdf417/CharacterSetECI.h
#        pdf417/ResultMetadata.h
#        pdf417/PerspectiveTransform.h
#        pdf417/CharacterSetECI.cpp
#        pdf417/DecoderResult.h
#        pdf417/ZXConfig.h
#        pdf417/DecodeStatus.h
#        pdf417/ZXBigInteger.h
#        pdf417/TextDecoder.h
#        pdf417/ReedSolomonEncoder.h
#        pdf417/BitWrapperBinarizer.h
#        pdf417/GridSampler.cpp
#        pdf417/ReedSolomonEncoder.cpp
#        pdf417/ZXNumeric.h
#        pdf417/TextUtfEncoding.h
#        pdf417/BarcodeFormat.cpp
#        pdf417/BitArray.h
#        pdf417/GenericGF.cpp
#        pdf417/WhiteRectDetector.h
#        pdf417/ResultPoint.cpp
#        pdf417/MultiFormatWriter.h
#        pdf417/CustomData.h
#        pdf417/ByteArray.h
#        pdf417/Reader.h
#        pdf417/MultiFormatReader.h
#        pdf417/DecodeHints.cpp
#        pdf417/GenericLuminanceSource.h
#        pdf417/HybridBinarizer.cpp
#        pdf417/BitMatrix.h
#        pdf417/GlobalHistogramBinarizer.cpp
#        pdf417/MultiFormatReader.cpp
#        pdf417/ZXNullable.h
#        pdf417/PerspectiveTransform.cpp
#        pdf417/WhiteRectDetector.cpp
#        pdf417/LuminanceSource.h
#        pdf417/ResultPoint.h
#        pdf417/DecodeHints.h
#        pdf417/ZXTestSupport.h
#        pdf417/BitSource.h
#        pdf417/GridSampler.h
#        pdf417/TextEncoder.cpp
#        pdf417/BinaryBitmap.h
#        pdf417/GenericGFPoly.h
#        pdf417/TextUtfEncoding.cpp
#        pdf417/ResultMetadata.cpp
#        pdf417/GenericLuminanceSource.cpp
#        pdf417/Result.h
#        pdf417/BitSource.cpp
#        pdf417/ByteMatrix.h
#        pdf417/BitMatrix.cpp
#        pdf417/BitArray.cpp
#        pdf417/GenericGFPoly.cpp
#        pdf417/ReedSolomonDecoder.cpp


        )

target_link_libraries(zxing_pdf417 ${OpenCV_LIBS})