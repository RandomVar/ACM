/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int sum=l1->val+l2->val;
      int res=0;
      ListNode *t=new ListNode(sum%10);
      ListNode* p=new ListNode(0);
      p->next=t;
      res=sum/10;
      l1=l1->next;
      l2=l2->next;
      while(l1!=NULL||l2!=NULL)
      {
        if(l1==NULL)
        {
          while(res&&l2!=NULL)
          {
            res=res+l2->val;
          ListNode* tmp=new ListNode(res%10);
          res=res/10;
          l2=l2->next;
          t->next=tmp;
          t=t->next;
          }
          t->next=l2;
           break;
        }
        else if(l2==NULL)
        {
           while(res&&l1!=NULL)
          {
            res=res+l1->val;
            ListNode* tmp=new ListNode(res%10);
            res=res/10;
            l1=l1->next;
          t->next=tmp;
          t=t->next;
          }
          t->next=l1;
          break;
        }
        else{
          sum=l1->val+l2->val+res;
          ListNode* tmp=new ListNode(sum%10);
          t->next=tmp;
          t=t->next;
          res=sum/10;
          l1=l1->next;
          l2=l2->next;
        }
      }
      if(res)
      {
        ListNode* tmp=new ListNode(res);
          t->next=tmp;
          t=t->next;
      }
      p=p->next;
    return p;
    }
};
int main()
{
  Solution sol;
  ListNode *p1=new ListNode(1);
  ListNode *t=new ListNode(8);
  p1->next=t;
  // t->next=new ListNode(3);
  ListNode *p2=new ListNode(0);
  // t=new ListNode(6);
  // p2->next=t;
  // t->next=new ListNode(4);
  
  cout<<sol.addTwoNumbers(p1,p2)->val;
  int x;
  cin>>x;

}