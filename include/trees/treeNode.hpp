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
	int file;
	TreeList* children;
	string ubication;
public:
	TreeNode();
	TreeNode(string val);
	TreeNode(string val, int file);
	void setParent(TreeNode* node);
	void setData(string val);
	void setChildren(TreeList* list);
	void setUbication(string ubication);
	TreeNode* getParent();
	string getData();
	int isFile();
	TreeList* getChildren();
	string getUbication();
	virtual ~TreeNode();
};

} /* namespace trees */

#endif /* TREENODE_HPP_ */
