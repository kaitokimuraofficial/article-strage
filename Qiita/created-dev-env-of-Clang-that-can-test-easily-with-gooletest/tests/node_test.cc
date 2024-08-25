extern "C" {
#include "../src/node.h"
}

#include <gtest/gtest.h>
#include <string>

TEST(NodeTest, onlyHead) {
    Node *head = NULL;

    EXPECT_EQ(len(head), 0);
    testing::internal::CaptureStdout();
    print(head);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "Head is NULL\n");
}

TEST(NodeTest, insertAndDelete) {
    Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 11);

    EXPECT_EQ(len(head), 2);
    testing::internal::CaptureStdout();
    print(head);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "10 -> 11\n");


    insertAtBeginning(&head, 2);

    EXPECT_EQ(len(head), 3);
    testing::internal::CaptureStdout();
    print(head);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "2 -> 10 -> 11\n");


    insertAtIndex(&head, 100, 1);

    EXPECT_EQ(len(head), 4);
    testing::internal::CaptureStdout();
    print(head);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "2 -> 100 -> 10 -> 11\n");


    deleteAtIndex(&head, 1);

    EXPECT_EQ(len(head), 3);
    testing::internal::CaptureStdout();
    print(head);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "2 -> 10 -> 11\n");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
