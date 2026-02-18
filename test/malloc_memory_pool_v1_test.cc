#include "memory/malloc_memory_pool_v1.h"

#include <glog/logging.h>
#include <gtest/gtest.h>
#include <new>

struct Node {
  int x;
  int y;
};

/**
 * 测试：MallocMemoryPoolV1 基本 allocate / deallocate 流程
 */
TEST(MallocMemoryPoolV1Test, AllocateAndFree) {
  BaseMemoryPool* pool = new MallocMemoryPoolV1();

  void* mem = pool->allocate(sizeof(Node));
  ASSERT_NE(mem, nullptr) << "Allocation failed";

  Node* node = new (mem) Node{1, 2};
  EXPECT_EQ(node->x, 1);
  EXPECT_EQ(node->y, 2);

  // 显式析构（placement new 的标准流程）
  node->~Node();

  // 正确释放
  pool->deallocate(&mem);

  delete pool;
}

/**
 * 测试：allocate(0) 行为
 */
TEST(MallocMemoryPoolV1Test, AllocateZeroSize) {
  MallocMemoryPoolV1 pool;
  void* mem = pool.allocate(0);
  EXPECT_EQ(mem, nullptr);
}

/**
 * 测试：deallocate(nullptr) 不崩溃
 */
TEST(MallocMemoryPoolV1Test, DeallocateNullptr) {
  MallocMemoryPoolV1 pool;
  EXPECT_NO_THROW(pool.deallocate(nullptr));
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  google::InitGoogleLogging(argv[0]);
  FLAGS_logtostderr = 1;

  int ret = RUN_ALL_TESTS();

  google::ShutdownGoogleLogging();
  return ret;
}