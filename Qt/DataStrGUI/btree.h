#ifndef BTREE_H
#define BTREE_H

#include <stdlib.h>
#include <iostream>

template<int M, typename K>
class BTreeNode
{
public:
    BTreeNode<M, K>() :
        m_keyNum(0),
        m_childNum(0),
        m_isLeaf(true),
        m_keys(NULL),
        m_childs(NULL),
        m_parentNode(NULL)
    {
        m_keys = new K[M - 1];
        m_childs = new BTreeNode<M, K> * [M];
        assert(m_keys);
        assert(m_childs);
    }

    void doInsert(const K & key)
    {
        int idx = 0;
        int keyNum = getKeyNum();
        while(idx < keyNum)
        {
            K keyInNode = getKeyByIdx(idx);
            if(key > keyInNode)
            {
                ++idx;
            }
            else
            {
                break;
            }
        }

        moveKey(idx);
        m_keys[idx] = key;
        ++m_keyNum;
    }

    void checkSplit()
    {
        if(m_keyNum == M)
        {
            doSplit();
        }
    }

    const K & getKeyByIdx(const int & idx) const
    {
        return m_keys[idx];
    }

    const int & getKeyNum() const
    {
        return m_keyNum;
    }

    const bool & isLeafNode() const
    {
        return m_isLeaf;
    }

    BTreeNode<M, K> * getChildByIdx(const int & idx) const
    {
        return m_childs[idx];
    }

    BTreeNode<M, K> * parentNode() const
    {
        return m_parentNode;
    }

private:
    int m_keyNum;
    int m_childNum;
    bool m_isLeaf;
    K * m_keys;
    /**  Use dual pointer to provent recursively call conctructor  **/
    BTreeNode<M, K> ** m_childs;
    BTreeNode<M, K> * m_parentNode;

    void moveKey(const int & startIdx)
    {
        for (int idx = m_keyNum; idx > startIdx; --idx)
        {
            m_keys[idx + 1] = m_keys[idx];
        }
    }

    void doSplit()
    {

    }

    int calBounder() const
    {
        return m_keyNum / 2;
    }
};

template<int M, typename K>
class BTree
{
public:
    BTree() :
        m_(M)
    {
        m_rootNode = new BTreeNode<M, K>();
        assert(m_rootNode);
    }

    BTreeNode<M, K> * search(BTreeNode<M, K> * startNode, const K & targetKey)
    {
        int i = 0;
        int keyNum = startNode->getKeyNum();
        if(keyNum == 0)
        {
            return NULL;
        }

        K keyFromNode = startNode->getKeyByIdx(i);
        while(i < keyNum && targetKey > keyFromNode)
        {
            ++i;
            K keyFromNode = startNode->getKeyByIdx(i);
        }

        if(keyFromNode == targetKey)
        {
            return startNode;
        }
        else if(startNode->isLeafNode())
        {
             return NULL;
        }
        return search(startNode->getChildByIdx(i), targetKey);
    }

    void insert(const K & keyToBeInserted)
    {
        BTreeNode<M, K> * insertPointNode = searchInsertPoint(m_rootNode, keyToBeInserted);
        assert(insertPointNode);
        insertPointNode->doInsert(keyToBeInserted);
        insertPointNode->checkSplit();
    }
private:
    int m_;
    BTreeNode<M, K> * m_rootNode;

    BTreeNode<M, K> * searchInsertPoint(BTreeNode<M, K> * startNode, const K keyToBeInserted)
    {
        int idx = 0;
        int curNodeKeyNum = startNode->getKeyNum();
        while(idx < curNodeKeyNum)
        {
            const K & keyInNode = startNode->getKeyByIdx(idx);
            if(keyToBeInserted > keyInNode)
            {
                ++idx;
                continue;
            }
            else
            {
                break;
            }
        }

        if(startNode->isLeafNode())
        {
            return startNode;
        }

        BTreeNode<M, K> * childNode = startNode->getChildByIdx(idx);
        return searchInsertPoint(childNode, keyToBeInserted);
    }
};
#endif // BTREE_H
