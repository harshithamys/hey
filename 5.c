#include &lt;stdbool.h&gt;
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

struct Node {
int data;
struct Node* next;
};


void push(struct Node** head_ref, int new_data);


bool isPresent(struct Node* head, int data);


struct Node* getUnion(struct Node* head1,struct Node* head2)
{
struct Node* result = NULL;
struct Node *t1 = head1, *t2 = head2;


while (t1 != NULL) {
push(&amp;result, t1-&gt;data);
t1 = t1-&gt;next;
}


while (t2 != NULL) {
if (!isPresent(result, t2-&gt;data))
push(&amp;result, t2-&gt;data);
t2 = t2-&gt;next;
}

return result;
}


struct Node* getIntersection(struct Node* head1,struct Node* head2)
{
struct Node* result = NULL;
struct Node* t1 = head1;

while (t1 != NULL) {
if (isPresent(head2, t1-&gt;data))
push(&amp;result, t1-&gt;data);
t1 = t1-&gt;next;
}

return result;
}



void push(struct Node** head_ref, int new_data)
{

struct Node* new_node
= (struct Node*)malloc(sizeof(struct Node));


new_node-&gt;data = new_data;

new_node-&gt;next = (*head_ref);


(*head_ref) = new_node;
}


void printList(struct Node* node)
{
while (node != NULL) {
printf(&quot;%d &quot;, node-&gt;data);
node = node-&gt;next;
}
}


bool isPresent(struct Node* head, int data)
{
struct Node* t = head;
while (t != NULL) {
if (t-&gt;data == data)

return 1;
t = t-&gt;next;
}
return 0;
}


int main()
{

struct Node* head1 = NULL;
struct Node* head2 = NULL;
struct Node* intersecn = NULL;
struct Node* unin = NULL;

push(&amp;head1, 20);
push(&amp;head1, 4);
push(&amp;head1, 15);
push(&amp;head1, 10);


push(&amp;head2, 10);
push(&amp;head2, 2);
push(&amp;head2, 4);
push(&amp;head2, 8);

intersecn = getIntersection(head1, head2);
unin = getUnion(head1, head2);

printf(&quot;\n First list is \n&quot;);
printList(head1);

printf(&quot;\n Second list is \n&quot;);
printList(head2);

printf(&quot;\n Intersection list is \n&quot;);
printList(intersecn);

printf(&quot;\n Union list is \n&quot;);
printList(unin);

return 0;
}
