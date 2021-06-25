#pragma once

#include <string>
#include <vector>

#include <map>

class trie_t {
public:
  trie_t();
  ~trie_t();

  trie_t(const trie_t &other);
  trie_t &operator=(const trie_t &other);

  /**
   * Insert specified string
   * @param str
   */
  void insert(const std::string &str);
  
  /**
   * Remove specified string
   * @param str
   * @return return true if specified string was in container
   */
  bool erase(const std::string &str);
  /**
   * Made your container empty
   */
  void clear();

  /**
   * @param str
   * @return true if there is at least one specified string in your container
   */
  bool find(const std::string &str) const;
  /**
   * @param prefix
   * @return number of strings which starts with specified prefix in your container
   */
  size_t count_with_prefix(const std::string &prefix) const;

  /**
   * IMAGINE that you sort all strings in you container in lexicographic order.
   * You should return string on position index in this order
   * @param index
   */
  std::string operator[](size_t index) const;

  /**
   * @return All strings from your container in lexicographic order.
   */
  std::vector<std::string> to_vector() const;

  /**
   * @return Number of strings in container
   */
  inline size_t size() const {
      return size_;
  }
  
  /**
   * @return true if container is empty :)
   */
  inline bool empty() const {
      return size_ == 0;
  }

  /**
   * Exchange content of this and other
   * @param other
   */
  void swap(trie_t &other);

private:
  size_t size_;
  size_t string_end_count;
  
  std::map<char, trie_t> children;
  
  const trie_t* reach(const std::string &str) const;
};


// vim: set bs=2 tabstop=2 softtabstop=2 shiftwidth=2 expandtab
