//
// Created by demo on 2024/11/12.
//

#ifndef MY_APPLICATION_NATIVELIB_HPP
#define MY_APPLICATION_NATIVELIB_HPP

#include <jni.h>
#include <string>
#include <android/log.h>
#include <android/bitmap.h>
#include <opencv2/opencv.hpp>
#include <android/asset_manager_jni.h>
#include <android/log.h>

// ncnn
#include "net.h"
#include "benchmark.h"


static std::vector<std::string> squeezenet_words;
static ncnn::Net squeezenet;
static ncnn::Net squeezenet_gpu;

jstring _Nullable stringFromJNI(
        JNIEnv *_Nullable env,
        jobject _Nullable /* this */);


jobject _Nullable cvtColor(
        JNIEnv *_Nullable env,
        jobject _Nullable /* this */,
        jobject _Nullable bitmap);

jboolean ncnnInit(
        JNIEnv *_Nullable env,
        jobject _Nullable /* this */,
        jobject _Nullable assetManager);

jstring _Nullable ncnnDetect(
        JNIEnv *_Nullable env,
        jobject _Nullable /* this */,
        jobject _Nullable bitmap,
        jboolean use_gpu
);

void copyPixel4Mat(
        void *_Nonnull const pixels,
        const cv::Mat &mat);

static std::vector<std::string> split_string(
        const std::string &str,
        const std::string &delimiter);

namespace squeezenet_v1_1_param_id {
    const int LAYER_data = 0;
    const int BLOB_data = 0;
    const int LAYER_conv1 = 1;
    const int BLOB_conv1 = 1;
    const int LAYER_relu_conv1 = 2;
    const int BLOB_conv1_relu_conv1 = 2;
    const int LAYER_pool1 = 3;
    const int BLOB_pool1 = 3;
    const int LAYER_fire2_squeeze1x1 = 4;
    const int BLOB_fire2_squeeze1x1 = 4;
    const int LAYER_fire2_relu_squeeze1x1 = 5;
    const int BLOB_fire2_squeeze1x1_fire2_relu_squeeze1x1 = 5;
    const int LAYER_splitncnn_0 = 6;
    const int BLOB_fire2_squeeze1x1_fire2_relu_squeeze1x1_splitncnn_0 = 6;
    const int BLOB_fire2_squeeze1x1_fire2_relu_squeeze1x1_splitncnn_1 = 7;
    const int LAYER_fire2_expand1x1 = 7;
    const int BLOB_fire2_expand1x1 = 8;
    const int LAYER_fire2_relu_expand1x1 = 8;
    const int BLOB_fire2_expand1x1_fire2_relu_expand1x1 = 9;
    const int LAYER_fire2_expand3x3 = 9;
    const int BLOB_fire2_expand3x3 = 10;
    const int LAYER_fire2_relu_expand3x3 = 10;
    const int BLOB_fire2_expand3x3_fire2_relu_expand3x3 = 11;
    const int LAYER_fire2_concat = 11;
    const int BLOB_fire2_concat = 12;
    const int LAYER_fire3_squeeze1x1 = 12;
    const int BLOB_fire3_squeeze1x1 = 13;
    const int LAYER_fire3_relu_squeeze1x1 = 13;
    const int BLOB_fire3_squeeze1x1_fire3_relu_squeeze1x1 = 14;
    const int LAYER_splitncnn_1 = 14;
    const int BLOB_fire3_squeeze1x1_fire3_relu_squeeze1x1_splitncnn_0 = 15;
    const int BLOB_fire3_squeeze1x1_fire3_relu_squeeze1x1_splitncnn_1 = 16;
    const int LAYER_fire3_expand1x1 = 15;
    const int BLOB_fire3_expand1x1 = 17;
    const int LAYER_fire3_relu_expand1x1 = 16;
    const int BLOB_fire3_expand1x1_fire3_relu_expand1x1 = 18;
    const int LAYER_fire3_expand3x3 = 17;
    const int BLOB_fire3_expand3x3 = 19;
    const int LAYER_fire3_relu_expand3x3 = 18;
    const int BLOB_fire3_expand3x3_fire3_relu_expand3x3 = 20;
    const int LAYER_fire3_concat = 19;
    const int BLOB_fire3_concat = 21;
    const int LAYER_pool3 = 20;
    const int BLOB_pool3 = 22;
    const int LAYER_fire4_squeeze1x1 = 21;
    const int BLOB_fire4_squeeze1x1 = 23;
    const int LAYER_fire4_relu_squeeze1x1 = 22;
    const int BLOB_fire4_squeeze1x1_fire4_relu_squeeze1x1 = 24;
    const int LAYER_splitncnn_2 = 23;
    const int BLOB_fire4_squeeze1x1_fire4_relu_squeeze1x1_splitncnn_0 = 25;
    const int BLOB_fire4_squeeze1x1_fire4_relu_squeeze1x1_splitncnn_1 = 26;
    const int LAYER_fire4_expand1x1 = 24;
    const int BLOB_fire4_expand1x1 = 27;
    const int LAYER_fire4_relu_expand1x1 = 25;
    const int BLOB_fire4_expand1x1_fire4_relu_expand1x1 = 28;
    const int LAYER_fire4_expand3x3 = 26;
    const int BLOB_fire4_expand3x3 = 29;
    const int LAYER_fire4_relu_expand3x3 = 27;
    const int BLOB_fire4_expand3x3_fire4_relu_expand3x3 = 30;
    const int LAYER_fire4_concat = 28;
    const int BLOB_fire4_concat = 31;
    const int LAYER_fire5_squeeze1x1 = 29;
    const int BLOB_fire5_squeeze1x1 = 32;
    const int LAYER_fire5_relu_squeeze1x1 = 30;
    const int BLOB_fire5_squeeze1x1_fire5_relu_squeeze1x1 = 33;
    const int LAYER_splitncnn_3 = 31;
    const int BLOB_fire5_squeeze1x1_fire5_relu_squeeze1x1_splitncnn_0 = 34;
    const int BLOB_fire5_squeeze1x1_fire5_relu_squeeze1x1_splitncnn_1 = 35;
    const int LAYER_fire5_expand1x1 = 32;
    const int BLOB_fire5_expand1x1 = 36;
    const int LAYER_fire5_relu_expand1x1 = 33;
    const int BLOB_fire5_expand1x1_fire5_relu_expand1x1 = 37;
    const int LAYER_fire5_expand3x3 = 34;
    const int BLOB_fire5_expand3x3 = 38;
    const int LAYER_fire5_relu_expand3x3 = 35;
    const int BLOB_fire5_expand3x3_fire5_relu_expand3x3 = 39;
    const int LAYER_fire5_concat = 36;
    const int BLOB_fire5_concat = 40;
    const int LAYER_pool5 = 37;
    const int BLOB_pool5 = 41;
    const int LAYER_fire6_squeeze1x1 = 38;
    const int BLOB_fire6_squeeze1x1 = 42;
    const int LAYER_fire6_relu_squeeze1x1 = 39;
    const int BLOB_fire6_squeeze1x1_fire6_relu_squeeze1x1 = 43;
    const int LAYER_splitncnn_4 = 40;
    const int BLOB_fire6_squeeze1x1_fire6_relu_squeeze1x1_splitncnn_0 = 44;
    const int BLOB_fire6_squeeze1x1_fire6_relu_squeeze1x1_splitncnn_1 = 45;
    const int LAYER_fire6_expand1x1 = 41;
    const int BLOB_fire6_expand1x1 = 46;
    const int LAYER_fire6_relu_expand1x1 = 42;
    const int BLOB_fire6_expand1x1_fire6_relu_expand1x1 = 47;
    const int LAYER_fire6_expand3x3 = 43;
    const int BLOB_fire6_expand3x3 = 48;
    const int LAYER_fire6_relu_expand3x3 = 44;
    const int BLOB_fire6_expand3x3_fire6_relu_expand3x3 = 49;
    const int LAYER_fire6_concat = 45;
    const int BLOB_fire6_concat = 50;
    const int LAYER_fire7_squeeze1x1 = 46;
    const int BLOB_fire7_squeeze1x1 = 51;
    const int LAYER_fire7_relu_squeeze1x1 = 47;
    const int BLOB_fire7_squeeze1x1_fire7_relu_squeeze1x1 = 52;
    const int LAYER_splitncnn_5 = 48;
    const int BLOB_fire7_squeeze1x1_fire7_relu_squeeze1x1_splitncnn_0 = 53;
    const int BLOB_fire7_squeeze1x1_fire7_relu_squeeze1x1_splitncnn_1 = 54;
    const int LAYER_fire7_expand1x1 = 49;
    const int BLOB_fire7_expand1x1 = 55;
    const int LAYER_fire7_relu_expand1x1 = 50;
    const int BLOB_fire7_expand1x1_fire7_relu_expand1x1 = 56;
    const int LAYER_fire7_expand3x3 = 51;
    const int BLOB_fire7_expand3x3 = 57;
    const int LAYER_fire7_relu_expand3x3 = 52;
    const int BLOB_fire7_expand3x3_fire7_relu_expand3x3 = 58;
    const int LAYER_fire7_concat = 53;
    const int BLOB_fire7_concat = 59;
    const int LAYER_fire8_squeeze1x1 = 54;
    const int BLOB_fire8_squeeze1x1 = 60;
    const int LAYER_fire8_relu_squeeze1x1 = 55;
    const int BLOB_fire8_squeeze1x1_fire8_relu_squeeze1x1 = 61;
    const int LAYER_splitncnn_6 = 56;
    const int BLOB_fire8_squeeze1x1_fire8_relu_squeeze1x1_splitncnn_0 = 62;
    const int BLOB_fire8_squeeze1x1_fire8_relu_squeeze1x1_splitncnn_1 = 63;
    const int LAYER_fire8_expand1x1 = 57;
    const int BLOB_fire8_expand1x1 = 64;
    const int LAYER_fire8_relu_expand1x1 = 58;
    const int BLOB_fire8_expand1x1_fire8_relu_expand1x1 = 65;
    const int LAYER_fire8_expand3x3 = 59;
    const int BLOB_fire8_expand3x3 = 66;
    const int LAYER_fire8_relu_expand3x3 = 60;
    const int BLOB_fire8_expand3x3_fire8_relu_expand3x3 = 67;
    const int LAYER_fire8_concat = 61;
    const int BLOB_fire8_concat = 68;
    const int LAYER_fire9_squeeze1x1 = 62;
    const int BLOB_fire9_squeeze1x1 = 69;
    const int LAYER_fire9_relu_squeeze1x1 = 63;
    const int BLOB_fire9_squeeze1x1_fire9_relu_squeeze1x1 = 70;
    const int LAYER_splitncnn_7 = 64;
    const int BLOB_fire9_squeeze1x1_fire9_relu_squeeze1x1_splitncnn_0 = 71;
    const int BLOB_fire9_squeeze1x1_fire9_relu_squeeze1x1_splitncnn_1 = 72;
    const int LAYER_fire9_expand1x1 = 65;
    const int BLOB_fire9_expand1x1 = 73;
    const int LAYER_fire9_relu_expand1x1 = 66;
    const int BLOB_fire9_expand1x1_fire9_relu_expand1x1 = 74;
    const int LAYER_fire9_expand3x3 = 67;
    const int BLOB_fire9_expand3x3 = 75;
    const int LAYER_fire9_relu_expand3x3 = 68;
    const int BLOB_fire9_expand3x3_fire9_relu_expand3x3 = 76;
    const int LAYER_fire9_concat = 69;
    const int BLOB_fire9_concat = 77;
    const int LAYER_drop9 = 70;
    const int BLOB_fire9_concat_drop9 = 78;
    const int LAYER_conv10 = 71;
    const int BLOB_conv10 = 79;
    const int LAYER_relu_conv10 = 72;
    const int BLOB_conv10_relu_conv10 = 80;
    const int LAYER_pool10 = 73;
    const int BLOB_pool10 = 81;
    const int LAYER_prob = 74;
    const int BLOB_prob = 82;
}

#endif //MY_APPLICATION_NATIVELIB_HPP
