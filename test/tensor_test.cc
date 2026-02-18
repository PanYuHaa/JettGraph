#include "core/tensor.h"

#include <glog/logging.h>
#include <gtest/gtest.h>

#include "core/utils.h"


TEST(TensorTest, CreateAndPrintFloatTensor2D) {
  Shape shape = {2, 3};
  Tensor<float> tensor(shape);

  EXPECT_EQ(shape.size(), 2);
  EXPECT_NO_THROW(tensor.Print());
}

TEST(TensorTest, CreateAndPrintIntTensor2D) {
  Shape shape = {3, 2};
  Tensor<int32_t> tensor(shape);

  EXPECT_NO_THROW(tensor.Print());
}

TEST(TensorTest, PrintNon2DTensorShouldFail) {
  Shape shape = {2, 3, 4};
  Tensor<float> tensor(shape);

  EXPECT_DEATH({ tensor.Print(); }, "only supports 2D tensor");
}

TEST(TensorTest, SupportDifferentDTypes) {
  {
    Shape shape = {2, 2};
    Tensor<float> t(shape);
  }
  {
    Shape shape = {2, 2};
    Tensor<int32_t> t(shape);
  }
  {
    Shape shape = {2, 2};
    Tensor<int16_t> t(shape);
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  google::InitGoogleLogging(argv[0]);
  FLAGS_logtostderr = 1;

  int ret = RUN_ALL_TESTS();

  google::ShutdownGoogleLogging();
  return ret;
}