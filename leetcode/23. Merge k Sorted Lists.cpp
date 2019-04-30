/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result=new ListNode(0);
        ListNode* head=result;
        vector<ListNode*> p;
        vector<ListNode*>::iterator it;
        for(int i=0;i<lists.size();i++)
        {
         if(lists[i]!=NULL) p.push_back(lists[i]);
        }
         while(p.size())
         {
           int ans=0x3f3f3f3f;
            vector<ListNode*>::iterator pos;
            for(it=p.begin();it!=p.end();it++)
            {
                // cout<<(*it)->val<<endl;
              if((*it)->val<ans)
              {
                ans=(*it)->val;
                pos=it;
              }
            }
            result->next=(*pos);
             cout<<"result"<<(*pos)->val<<endl;
            result=result->next;
            (*pos)=(*pos)->next;
            if((*pos)==NULL) 
            {
              p.erase(pos);
            }
         }
         return head->next;
    }
};