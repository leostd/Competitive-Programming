import random as rand
max_nodes = 40
test_cases = 1


print(test_cases)
def gen(root, n):
    print(n)
    nodes = [root]
    edges = []
    for cur in range(1,n+1):
        if cur == root:
            continue
        random_node = nodes[rand.randint(0, len(nodes)-1)]
        edges.append((cur, random_node))
        nodes.append(cur)
    rand.shuffle(edges)
    for (x,y) in edges:
        print('{} {}'.format(x, y))

for i in range(test_cases):
    nodes = rand.randint(2, max_nodes)
    root = rand.randint(1, nodes)
    gen(root,nodes)
