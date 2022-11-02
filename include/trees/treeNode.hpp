/*
 * treeNode.hpp
 *
 *  Created on: Aug 30, 2022
 *      Author: jsaavedr
 */

#ifndef TREENODE_HPP_
#define TREENODE_HPP_

#include "trees/treeList.hpp"

#include <iostream>
#include <cstring>
using namespace std;

namespace trees {

class TreeList;
class TreeNode {
private:
	TreeNode* parent;
	string data; //data can be of any type
	TreeList* children;
public:
	TreeNode();
	TreeNode(string val);
	void setParent(TreeNode* node);
	void setData(string val);
	void setChildren(TreeList* list);
	TreeNode* getParent();
	string getData();
	TreeList* getChildren();
	virtual ~TreeNode();
};

} /* namespace trees */

#endif /* TREENODE_HPP_ */
