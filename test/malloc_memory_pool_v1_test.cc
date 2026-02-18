#include "memory/malloc_memory_pool_v1.h"

#include <glog/logging.h>
#include <gtest/gtest.h>
#include <new>

struct Node {
  int x;
  int y;
};

TEST(MallocMemoryPoolV1Test, AllocateAndFree) {
  void* mem = MallocMemoryPoolV1::Instance().Allocate(sizeof(Node));
  ASSERT_NE(mem, nullptr) << "Allocation failed";

  Node* node = new (mem) Node{1, 2};
  EXPECT_EQ(node->x, 1);
  EXPECT_EQ(node->y, 2);

  node->~Node();

  MallocMemoryPoolV1::Instance().Deallocate(&mem);
}

TEST(MallocMemoryPoolV1Test, AllocateZeroSize) {
  void* mem = MallocMemoryPoolV1::Instance().Allocate(0);
  EXPECT_EQ(mem, nullptr);
}

TEST(MallocMemoryPoolV1Test, DeallocateNullptr) {
  EXPECT_NO_THROW(MallocMemoryPoolV1::Instance().Deallocate(nullptr));
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  google::InitGoogleLogging(argv[0]);
  FLAGS_logtostderr = 1;

  int ret = RUN_ALL_TESTS();

  google::ShutdownGoogleLogging();
  return ret;
}