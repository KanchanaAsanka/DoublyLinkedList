#include<iostream>
#include "LinkedList.h"
#include <gtest/gtest.h>

using namespace std;

TEST(DoublyLinkedListTest, isEmpty) 
{
  DoublyLinkedList<int> list;
  EXPECT_TRUE(list.isEmpty());
}

TEST(DoublyLinkedList, AddToTail)
{
  DoublyLinkedList<int> list;
  EXPECT_TRUE(list.isEmpty());
  list.AddToTail(2);
  EXPECT_FALSE(list.isEmpty());
}

TEST(DoublyLinkedList, AddToHead)
{
  DoublyLinkedList<int> list;
  EXPECT_TRUE(list.isEmpty());
  list.AddToHead(2);
  EXPECT_FALSE(list.isEmpty());
}

TEST(DoublyLinkedList, front)
{
  DoublyLinkedList<int> list;
  EXPECT_THROW(list.front(), std::runtime_error);
  list.AddToHead(2);
  EXPECT_EQ(2, list.front());
}

TEST(DoublyLinkedList, back)
{
  DoublyLinkedList<int> list;
  EXPECT_THROW(list.back(), std::runtime_error);
  list.AddToHead(2);
  list.AddToHead(1);
  list.AddToHead(3);
  EXPECT_EQ(2, list.back());
  list.AddToTail(4);
  EXPECT_EQ(4, list.back());
}

TEST(DoublyLinkedList, AddTo)
{
  DoublyLinkedList<int> list;
  EXPECT_FALSE(list.AddTo(2,25));
  EXPECT_TRUE(list.AddTo(1,25));
  EXPECT_FALSE(list.AddTo(3,48));
  EXPECT_EQ(25, list.front());
  EXPECT_EQ(25, list.back());
  EXPECT_FALSE(list.isEmpty());
}

TEST(DoublyLinkedList, findIndexData)
{
  DoublyLinkedList<int> list;
  EXPECT_THROW(list.findIndexData(1), std::runtime_error);
  list.AddToHead(2);
  list.AddToHead(3);
  list.AddTo(3,4);
  EXPECT_EQ(3, list.findIndexData(1));
  EXPECT_EQ(2, list.findIndexData(2));
  EXPECT_EQ(4, list.findIndexData(3));
  EXPECT_EQ(3, list.front());
  EXPECT_EQ(4, list.back());
}

TEST(DoublyLinkedList, findData)
{
  DoublyLinkedList<int> list;

  list.AddToHead(2);
  list.AddToHead(3);
  list.AddTo(3,4);
  EXPECT_TRUE(list.findData(3));
  EXPECT_TRUE(list.findData(2));
  EXPECT_TRUE(list.findData(4));
  EXPECT_FALSE(list.findData(5));
  EXPECT_EQ(3, list.front());
  EXPECT_EQ(4, list.back());
}

TEST(DoublyLinkedList, removeNode)
{
  DoublyLinkedList<int> list;
  EXPECT_FALSE(list.removeNode(25));
  list.AddTo(1,2);
  list.AddTo(2,2);
  list.AddTo(3,3);
  list.AddTo(4,40);
  list.AddTo(5,25);
  list.AddTo(6,8);
  list.AddTo(7,2);
  list.AddTo(8,3);

  EXPECT_TRUE(list.findData(2));
  EXPECT_TRUE(list.removeNode(2));
  EXPECT_FALSE(list.findData(2));
  EXPECT_FALSE(list.removeNode(2));

  EXPECT_TRUE(list.findData(3));
  EXPECT_TRUE(list.removeNode(3));
  EXPECT_FALSE(list.findData(3));  
  EXPECT_FALSE(list.removeNode(3));

  EXPECT_TRUE(list.findData(40));
  EXPECT_TRUE(list.removeNode(40));
  EXPECT_FALSE(list.findData(40));

  EXPECT_TRUE(list.findData(25));
  EXPECT_TRUE(list.removeNode(25));
  EXPECT_FALSE(list.findData(25));

  EXPECT_TRUE(list.findData(8));
  EXPECT_TRUE(list.removeNode(8));
  EXPECT_FALSE(list.findData(8)); 

  EXPECT_TRUE(list.isEmpty());      
}

TEST (DoublyLinkedList, removeNodefrom)
{

DoublyLinkedList<int> list;
  EXPECT_FALSE(list.removeNodefrom(2));
  list.AddTo(1,2);
  list.AddTo(2,3);
  list.AddTo(3,40);
  list.AddTo(4,25);
  list.AddTo(5,8);

  EXPECT_EQ(2, list.findIndexData(1));
  EXPECT_TRUE(list.removeNodefrom(1));
  EXPECT_EQ(3, list.findIndexData(1));
  EXPECT_FALSE(list.findData(2));

  EXPECT_FALSE(list.removeNodefrom(5));
  EXPECT_EQ(8, list.findIndexData(4));
  EXPECT_TRUE(list.removeNodefrom(4));
  EXPECT_EQ(3, list.findIndexData(1));
  EXPECT_FALSE(list.findData(8));

  EXPECT_EQ(40, list.findIndexData(2));
  EXPECT_TRUE(list.removeNodefrom(2));
  EXPECT_EQ(25, list.findIndexData(2));
  EXPECT_FALSE(list.findData(40));
 
 EXPECT_FALSE(list.isEmpty());
}

TEST (DoublyLinkedList, TypeString)
{
  DoublyLinkedList<string> list;

  list.AddToHead("First");
  list.AddToTail("last");
  EXPECT_FALSE(list.isEmpty());
  EXPECT_EQ("First", list.front());
  EXPECT_EQ("last", list.back());
  EXPECT_TRUE(list.findData("First"));
  EXPECT_FALSE(list.findData("first"));
  EXPECT_EQ("last", list.findIndexData(2));
  EXPECT_THROW(list.findIndexData(3), std::runtime_error);
  list.AddTo(2, "testing data");
  list.AddTo(1,"testing");
  EXPECT_EQ("testing", list.front());
  EXPECT_TRUE(list.removeNode("First"));
  EXPECT_FALSE(list.findData("First"));

}

int main() 
{
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

