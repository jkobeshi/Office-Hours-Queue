// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"
#include <string>

using namespace std;

// Add your test cases here

//LIST TESTS//
TEST(test_empty) {
    List<int> l;
    ASSERT_TRUE(l.empty());

    l.push_back(1);
    l.push_back(2);
    ASSERT_FALSE(l.empty());
    l.pop_back();
    l.pop_back();
    ASSERT_TRUE(l.empty());

    l.push_front(1);
    l.push_front(2);
    ASSERT_FALSE(l.empty());
    l.pop_front();
    l.pop_front();
    ASSERT_TRUE(l.empty());

    l.push_back(1);
    l.push_back(2);
    l.clear();
    ASSERT_TRUE(l.empty());
}

TEST(test_size) {
    List<int> l;
    l.push_back(1);
    ASSERT_EQUAL(l.size(), 1);
    l.push_back(5);
    l.push_back(2);
    ASSERT_EQUAL(l.size(), 3);
    l.clear();
}

TEST(test_front_back) {
    List<int> l;
    l.push_front(1);
    ASSERT_EQUAL(l.front(), 1);
    ASSERT_EQUAL(l.back(), 1);
    l.push_front(4);
    ASSERT_EQUAL(l.front(), 4);
    ASSERT_EQUAL(l.back(), 1);
    l.push_back(15);
    ASSERT_EQUAL(l.front(), 4);
    ASSERT_EQUAL(l.back(), 15);
    l.clear();
}

TEST(test_push_front_pop_front) {
    List<int> h;
    h.push_front(1);
    h.push_front(3);
    h.push_front(2);
    h.push_front(9);
    ASSERT_EQUAL(h.front(), 9);
    ASSERT_EQUAL(h.back(), 1);
    h.pop_front();
    ASSERT_EQUAL(h.front(), 2);
    ASSERT_EQUAL(h.back(), 1);
    h.pop_front();
    ASSERT_EQUAL(h.front(), 3);
    ASSERT_EQUAL(h.back(), 1);
    h.pop_front();
    ASSERT_EQUAL(h.front(), 1);
    ASSERT_EQUAL(h.back(), 1);
    h.pop_front();
    ASSERT_TRUE(h.size() == 0);
    ASSERT_TRUE(h.empty());
    h.clear();
}

TEST(test_push_front_pop_back) {
    List<int> h;
    h.push_front(1);
    h.push_front(3);
    h.push_front(2);
    h.push_front(9);
    ASSERT_EQUAL(h.front(), 9);
    ASSERT_EQUAL(h.back(), 1);
    h.pop_back();
    ASSERT_EQUAL(h.front(), 9);
    ASSERT_EQUAL(h.back(), 3);
    h.pop_back();
    ASSERT_EQUAL(h.front(), 9);
    ASSERT_EQUAL(h.back(), 2);
    h.pop_back();
    ASSERT_EQUAL(h.front(), 9);
    ASSERT_EQUAL(h.back(), 9);
    h.pop_back();
    ASSERT_TRUE(h.size() == 0);
    ASSERT_TRUE(h.empty());
    h.clear();
}

TEST(test_push_back_pop_front) {
    List<int> j;
    j.push_back(0);
    j.push_back(4);
    j.push_back(1);
    j.push_back(2);
    ASSERT_EQUAL(j.front(), 0);
    ASSERT_EQUAL(j.back(), 2);
    j.pop_front();
    ASSERT_EQUAL(j.front(), 4);
    ASSERT_EQUAL(j.back(), 2);
    j.pop_front();
    ASSERT_EQUAL(j.front(), 1);
    ASSERT_EQUAL(j.back(), 2);
    j.pop_front();
    ASSERT_EQUAL(j.front(), 2);
    ASSERT_EQUAL(j.back(), 2);
    j.pop_front();
    ASSERT_TRUE(j.size() == 0);
    ASSERT_TRUE(j.empty());
    j.clear();
}

TEST(test_push_back_pop_back) {
    List<int> j;
    j.push_back(0);
    j.push_back(4);
    j.push_back(1);
    j.push_back(2);
    ASSERT_EQUAL(j.front(), 0);
    ASSERT_EQUAL(j.back(), 2);
    j.pop_back();
    ASSERT_EQUAL(j.front(), 0);
    ASSERT_EQUAL(j.back(), 1);
    j.pop_back();
    ASSERT_EQUAL(j.front(), 0);
    ASSERT_EQUAL(j.back(), 4);
    j.pop_back();
    ASSERT_EQUAL(j.front(), 0);
    ASSERT_EQUAL(j.back(), 0);
    j.pop_back();
    ASSERT_TRUE(j.size() == 0);
    ASSERT_TRUE(j.empty());
    j.clear();
}

TEST(test_push_pop_1) {
    List<string> i;
    i.push_front("ob");
    i.push_back("be");
    i.push_front("ko");
    i.push_back("e ");
    ASSERT_EQUAL(i.front(), "ko");
    ASSERT_EQUAL(i.back(), "e ");
    i.pop_back();
    ASSERT_EQUAL(i.front(), "ko");
    ASSERT_EQUAL(i.back(), "be");
    i.pop_front();
    ASSERT_EQUAL(i.front(), "ob");
    ASSERT_EQUAL(i.back(), "be");
    i.pop_back();
    ASSERT_EQUAL(i.front(), "ob");
    ASSERT_EQUAL(i.back(), "ob");
    i.pop_front();
    ASSERT_TRUE(i.size() == 0);
    ASSERT_TRUE(i.empty());
    i.clear();
}

TEST(test_push_pop_2) {
    List<string> i;
    i.push_back("be");
    i.push_front("ob");
    i.push_back("e ");
    i.push_front("ko");
    ASSERT_EQUAL(i.front(), "ko");
    ASSERT_EQUAL(i.back(), "e ");
    i.pop_front();
    ASSERT_EQUAL(i.front(), "ob");
    ASSERT_EQUAL(i.back(), "e ");
    i.pop_back();
    ASSERT_EQUAL(i.front(), "ob");
    ASSERT_EQUAL(i.back(), "be");
    i.pop_front();
    ASSERT_EQUAL(i.front(), "be");
    ASSERT_EQUAL(i.back(), "be");
    i.pop_back();
    ASSERT_TRUE(i.size() == 0);
    ASSERT_TRUE(i.empty());
    i.clear();
}

TEST(test_clear) {
    List<string> k;
    ASSERT_TRUE(k.empty());
    k.clear();
    ASSERT_TRUE(k.empty());
    k.push_back("Hi");
    ASSERT_EQUAL(k.front(), "Hi");
    k.push_back("2");
    ASSERT_EQUAL(k.back(), "2");
    k.clear();
    ASSERT_TRUE(k.empty());
}


TEST(test_copy_all_and_copy_ctor) {
    List<string> i;
    i.push_back("me");
    i.push_front("hire");
    i.push_front("pls");
    i.push_back("!");

    List<string> copy_of_i(i);
    ASSERT_EQUAL(copy_of_i.front(), i.front());
    ASSERT_EQUAL(copy_of_i.back(), i.back());
    i.pop_back();
    copy_of_i.pop_back();
    ASSERT_EQUAL(copy_of_i.front(), i.front());
    ASSERT_EQUAL(copy_of_i.back(), i.back());
    i.pop_front();
    copy_of_i.pop_front();
    ASSERT_EQUAL(copy_of_i.front(), i.front());
    ASSERT_EQUAL(copy_of_i.back(), i.back());
    i.pop_back();
    copy_of_i.pop_back();
    ASSERT_EQUAL(copy_of_i.front(), i.front());
    ASSERT_EQUAL(copy_of_i.back(), i.back());
    i.pop_front();
    copy_of_i.pop_front();
    ASSERT_TRUE(i.empty());
    ASSERT_TRUE(copy_of_i.empty());
    i.clear();
}

//ITERATOR TESTS//
TEST(test_begin_end) {
    List<string> t;
    t.push_back("school");
    t.push_back("is");
    t.push_back("cool");
    t.push_back(".");
    List<string>::Iterator it = t.begin();
    ASSERT_EQUAL(*it, "school");
    List<string>::Iterator it2;
    ASSERT_EQUAL(it2, t.end());
    t.clear();
}

TEST(test_insert_erase_1) {
    List<string> b;
    b.push_front("A");
    b.push_front("EECS 280");
    b.push_front("that");
    b.push_front("Gimme");

    b.insert(b.begin(), "G-G-G-");
    ASSERT_EQUAL(b.front(), "G-G-G-");
    ASSERT_EQUAL(b.size(), 5);
    b.erase(b.begin());
    ASSERT_EQUAL(b.front(), "Gimme");
    ASSERT_EQUAL(b.size(), 4);
    b.insert(b.end(), "!!!");
    ASSERT_EQUAL(b.size(), 5);
    ASSERT_EQUAL(b.back(), "!!!");
    b.pop_front();
    b.pop_front();
    b.pop_front();
    b.pop_front();
    ASSERT_EQUAL(b.size(), 1);
    ASSERT_EQUAL(b.front(), "!!!");
    b.clear();
}

TEST(test_insert_erase_2) {
    List<int> b;
    b.push_front(4);
    b.push_front(3);
    b.push_front(2);
    b.push_front(1);

    b.erase(b.begin());
    ASSERT_EQUAL(b.front(), 2);
    ASSERT_EQUAL(b.size(), 3);
    b.insert(b.begin(), 0);
    ASSERT_EQUAL(b.front(), 0);
    ASSERT_EQUAL(b.size(), 4);
    b.insert(b.end(), 5);
    ASSERT_EQUAL(b.back(), 5);
    ASSERT_EQUAL(b.size(), 5);
    List<int>::Iterator it = b.begin();
    ++it, ++it, ++it; ++it;
    ASSERT_EQUAL(*it, 5);
    b.erase(it);
    ASSERT_EQUAL(b.back(), 4);
    ASSERT_EQUAL(b.size(), 4);
    b.clear();
}

TEST(test_insert_erase_3) {
    List<int> b;
    for (int i = 1; i <= 5; i++) {
        b.push_back(i);
    }
    List<int>::Iterator it = b.begin();
    ++it; ++it;
    b.erase(it);
    ASSERT_EQUAL(b.size(), 4);
    List<int>::Iterator it2 = b.begin();
    ++it2; ++it2;
    ASSERT_EQUAL(*it2, 4);
    b.insert(it2, 3);
    ASSERT_EQUAL(b.size(), 5);
    List<int>::Iterator it3 = b.begin();
    ++it3; ++it3;
    ASSERT_EQUAL(*it3, 3);
    b.clear();
}

TEST(test_list_big_three) {
    List<int> k;
    k.push_back(1);
    k.push_back(5);
    k.push_back(9);
    k.push_back(10);

    List<int> k_copy2;
    k_copy2.push_back(0);
    ASSERT_EQUAL(k_copy2.front(), 0);

    List<int> k_copy(k);
    k_copy2 = k;

    ASSERT_EQUAL(k_copy.size(), k.size());
    ASSERT_EQUAL(k_copy.front(), k.front());
    ASSERT_EQUAL(k_copy.back(), k.back());
    ASSERT_EQUAL(k_copy2.size(), k.size());
    ASSERT_EQUAL(k_copy2.front(), k.front());
    ASSERT_EQUAL(k_copy2.back(), k.back());
    k.pop_front();
    k.pop_back();
    ASSERT_NOT_EQUAL(k_copy.size(), k.size());
    ASSERT_NOT_EQUAL(k_copy.front(), k.front());
    ASSERT_NOT_EQUAL(k_copy.back(), k.back());
    ASSERT_NOT_EQUAL(k_copy2.size(), k.size());
    ASSERT_NOT_EQUAL(k_copy2.front(), k.front());
    ASSERT_NOT_EQUAL(k_copy2.back(), k.back());
    k_copy2 = k;
    ASSERT_EQUAL(k_copy2.size(), k.size());
    ASSERT_EQUAL(k_copy2.front(), k.front());
    ASSERT_EQUAL(k_copy2.back(), k.back());
}

TEST(test_iterator) {
    List<int> k;
    k.push_back(1);
    k.push_back(5);
    k.push_back(9);
    k.push_back(10);

    List<int>::Iterator it = k.begin();
    ASSERT_EQUAL(*it, 1);
    ++it;
    ASSERT_EQUAL(*it, 5);
    ++it; 
    ASSERT_EQUAL(*it, 9);

    List<int>::Iterator it_copy(it);
    ASSERT_EQUAL(*it_copy, 9);
    --it_copy;
    k.erase(it);
    ++it_copy;
    ASSERT_EQUAL(k.size(), 3);
    ASSERT_EQUAL(*it_copy, 10);
    k.insert(it_copy, 20);
    ASSERT_EQUAL(k.size(), 4);
    --it_copy;
    ASSERT_EQUAL(*it_copy, 20);
    *it_copy = *it_copy + 1;
    ASSERT_EQUAL(*it_copy, 21);
    ASSERT_EQUAL(k.size(), 4);
}

TEST_MAIN()
