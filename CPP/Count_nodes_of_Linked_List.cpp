// count the number of nodes in a  linked list
int getCount(struct Node* head){
    
        //Code here
        int cnt=0;
      Node *curr = head;
      while(curr != NULL){
          cnt++;
          curr = curr->next;
      }
      return cnt;
    }
