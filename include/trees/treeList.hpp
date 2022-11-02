/*
 * childrenList.hpp
 *
 *  Created on: Aug 31, 2022
 *      Author: jsaavedr
 */

#ifndef CHILDRENLIST_HPP_
#define CHILDRENLIST_HPP_

#include "trees/treeListNode.hpp"

#include <iostream>
#include <cstring>
using namespace std;


namespace trees {

class TreeNode;
class TreeListNode;
class TreeList {
private:
	TreeListNode* head;
public:
	TreeList();
	TreeListNode* getHead();
	void insertFirst(TreeNode* treeNode);
	void removeFirst();
	void remove(string val);
	void removeAll();
	bool isEmpty();
	TreeNode* find(string val);
	void print();
	virtual ~TreeList();
};

} /* namespace trees */

#endif /* CHILDRENLIST_HPP_ */
