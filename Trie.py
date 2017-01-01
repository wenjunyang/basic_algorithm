#!/usr/bin/python2
# -*-coding:utf-8-*-


class TrieNode:
    def __init__(self, char):
        self.char = char
        self.frequency = 0
        self.child = {}
        self.end_cnt = 0

    def add_child(self, char):
        if self.child.has_key(char):
            child = self.child[char]
        else:
            child = TrieNode(char)
            self.child[char] = child
        return child

    def find_child(self, char):
        return self.child.get(char, None)

    def inc_frequency(self, cnt=1):
        self.frequency += cnt

    def inc_end_cnt(self, cnt=1):
        self.end_cnt += cnt


class Trie:

    def __init__(self):
        self.root = TrieNode(None)

    def build_tree(self, words):
        for word in words:
            parent = self.root
            parent.inc_frequency()
            for i in range(0, len(word)):
                char = word[i]
                parent = parent.add_child(char)
                parent.inc_frequency()
                parent.inc_end_cnt(1 if i + 1 == len(word) else 0)

    def _cal_prefix(self, current_node, current_prefix, result):
        if current_node.end_cnt > 0:
            result[current_prefix] = current_node.end_cnt
        for child in current_node.child.itervalues():
            self._cal_prefix(child, current_prefix + child.char, result)

    def _find_prefix_node(self, prefix):
        current = self.root
        for char in prefix:
            current = current.find_child(char)
            if not current:
                return None
        return current

    def prefix_words(self, prefix):
        result = {}
        current = self._find_prefix_node(prefix)
        if not current:
            return result
        else:
            self._cal_prefix(current, prefix, result)
        return result

    def prefix_cnt(self, prefix):
        node = self._find_prefix_node(prefix)
        return 0 if not node else node.frequency

if __name__ == '__main__':
    words = ["com", "com", "company", "go", "gobang", "you", "me", "i"]

    trie = Trie()
    trie.build_tree(words)

    result = trie.prefix_words("com")

    for (k, v) in result.iteritems():
        print "%s:%d" % (k, v)

    print(trie.prefix_cnt(""))
    print(trie.prefix_cnt("c"))
    print(trie.prefix_cnt("com"))
    print(trie.prefix_cnt("g"))


