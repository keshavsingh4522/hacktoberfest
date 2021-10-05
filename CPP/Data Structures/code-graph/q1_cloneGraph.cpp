
/*
   Problem link:--- https://leetcode.com/problems/clone-graph
   submission link:- https://leetcode.com/problems/clone-graph/submissions/
   =======================================================================
    NOTE: ONLY THE FUNCTION GIVEN IN LEETCODE IS COMPLETED IN THE GIVEN CODE....

   =======================================================================
*/
// leetcode
class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return node;
        map<Node *, Node *> m;
        queue<Node *> q;

        q.push(node);
        Node *newGraph;
        newGraph = new Node();
        newGraph->val = node->val;
        m[node] = newGraph;

        while (!q.empty())
        {
            Node *u = q.front();
            q.pop();
            vector<Node *> v = u->neighbors;
            int n = v.size();
            for (int i = 0; i < n; i++)
            {
                if (m[v[i]] == NULL)
                {
                    newGraph = new Node();
                    newGraph->val = v[i]->val;
                    m[v[i]] = newGraph;
                    q.push(v[i]);
                }
                m[u]->neighbors.push_back(m[v[i]]);
            }
        }
        return m[node];
    }
};