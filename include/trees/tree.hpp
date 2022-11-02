/*
 * tree.hpp
 *
 *  Created on: Aug 31, 2022
 *      Author: jsaavedr
 */

#ifndef TREE_HPP_
#define TREE_HPP_

#include "trees/treeNode.hpp"

#include <iostream>
#include <cstring>
using namespace std;

namespace trees {

class Tree {
private:
	TreeNode* root;
public:
	Tree();
	void setRoot(TreeNode* node);
	void insert(TreeNode* node, TreeNode* parent);
	void insert(string child, string parent);
	TreeNode* find_rec(string val, TreeNode* node);
	TreeNode* find(string val);
	void traverse_rec(TreeNode* node, int level);
	void traverse();
	virtual ~Tree();
};

} /* namespace trees */

#endif /* TREE_HPP_ */
