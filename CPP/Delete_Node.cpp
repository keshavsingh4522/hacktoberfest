/*
   * कर्मणये वाधिकारस्ते मां फलेषु कदाचन ।
   * मां कर्मफलहेतुर्भू: मांते संङगोस्त्वकर्मणि ॥
*/

#include <bits/stdc++.h>
using namespace std;

#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

/*
   *  Given a singly linked list and an integer x.Delete xth node from the singly linked list.
*/
Node* deleteNode(Node* head, int x) {
    if (head == NULL) return NULL;
    if (x == 1) return head->next;

    Node* temp = head;
    for (int i = 0; i < x - 2; i++) {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
}

void solve() {
    int n;
    cin >> n;
    Node* head = NULL;
    Node* temp = head;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (head == NULL) {
            head = new Node(val);
            temp = head;
        }
        else {
            temp->next = new Node(val);
            temp = temp->next;
        }
    }
    int x;
    cin >> x;
    head = deleteNode(head, x);
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int32_t main() {
     system("clear");
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("/Users/aman/Documents/30 Days of Code/input.txt", "r", stdin);
    freopen("/Users/aman/Documents/30 Days of Code/output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
    cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;

    return 0;
}
