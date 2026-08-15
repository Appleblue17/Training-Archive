#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const int MAXQ = 200010;
const int MAXNODE = 22000000;

struct Point {
    int left, right, stamp, size;
    int rev;
    LL add, pos;
    int val, sum;
} tr[MAXNODE];

int now, tot, key, q;
int rtL[MAXQ], rtR[MAXQ];

int check(int t) {
    if (tr[t].stamp != now) {
        int p = ++tot;
        tr[p] = tr[t];
        tr[p].stamp = now;
        return p;
    }
    return t;
}

int update(int t) {
    if (!t) return 0;
    tr[t].sum =
        tr[tr[t].left].sum +
        tr[tr[t].right].sum +
        tr[t].val;
    tr[t].size =
        tr[tr[t].left].size +
        tr[tr[t].right].size + 1;
    return t;
}

int reverseTree(int t) {
    if (!t) return 0;
    t = check(t);
    tr[t].rev ^= 1;
    tr[t].add *= -1;
    tr[t].pos *= -1;
    swap(tr[t].left, tr[t].right);
    return t;
}

int addPosition(int t, LL value) {
    if (!t) return 0;
    t = check(t);
    tr[t].add += value;
    tr[t].pos += value;
    return t;
}

int pushDown(int t) {
    if (!t) return 0;
    t = check(t);

    if (tr[t].rev) {
        if (tr[t].left)
            tr[t].left = reverseTree(tr[t].left);
        if (tr[t].right)
            tr[t].right = reverseTree(tr[t].right);
        tr[t].rev = 0;
    }

    if (tr[t].add) {
        if (tr[t].left)
            tr[t].left =
                addPosition(tr[t].left, tr[t].add);
        if (tr[t].right)
            tr[t].right =
                addPosition(tr[t].right, tr[t].add);
        tr[t].add = 0;
    }

    return t;
}

void split(int t, LL position, int &left, int &right) {
    if (!t) {
        left = right = 0;
        return;
    }

    t = pushDown(t);

    if (position <= tr[t].pos) {
        split(tr[t].left, position, left, right);
        tr[t].left = right;
        right = update(t);
    } else {
        split(tr[t].right, position, left, right);
        tr[t].right = left;
        left = update(t);
    }
}

int mergeTree(int left, int right) {
    if (!left || !right)
        return left | right;

    if (1LL * rand() *
            (tr[left].size + tr[right].size) <
        1LL * tr[left].size * RAND_MAX) {
        left = pushDown(left);
        tr[left].right =
            mergeTree(tr[left].right, right);
        return update(left);
    } else {
        right = pushDown(right);
        tr[right].left =
            mergeTree(left, tr[right].left);
        return update(right);
    }
}

void createPair(
    LL position,
    int &leftNode,
    int &rightNode,
    int value
) {
    leftNode = ++tot;
    rightNode = ++tot;

    tr[leftNode] = Point{};
    tr[rightNode] = Point{};

    tr[leftNode].stamp = tr[rightNode].stamp = now;
    tr[leftNode].pos = tr[rightNode].pos = position;
    tr[leftNode].val = tr[rightNode].val = value;

    update(leftNode);
    update(rightNode);
}

void solveCase() {
    scanf("%d", &q);

    tot = 0;
    key = 0;
    now = 0;
    tr[0] = Point{};

    createPair(0, rtL[0], rtR[0], 1);

    for (int i = 1; i <= q; ++i) {
        int opt;
        LL x, l, r;

        int Ll, Lr, Lm;
        int Rl, Rr, Rm;

        now = i;
        scanf("%d", &opt);

        rtL[i] = rtL[i - 1];
        rtR[i] = rtR[i - 1];

        if (opt == 1) {
            scanf("%lld", &x);
            x ^= key;

            split(rtL[i], x, Ll, Lr);
            split(rtR[i], x, Rl, Rr);

            createPair(x, Lm, Rm, 1);

            rtL[i] =
                mergeTree(mergeTree(Ll, Lm), Lr);
            rtR[i] =
                mergeTree(mergeTree(Rl, Rm), Rr);
        } else if (opt == 2) {
            scanf("%lld", &x);
            x ^= key;

            rtL[i] = addPosition(rtL[i], -x);
            rtR[i] = addPosition(rtR[i], x);
        } else if (opt == 3) {
            scanf("%lld%lld", &l, &r);
            l ^= key;
            r ^= key;

            split(rtL[i], l, Ll, Lr);
            split(Lr, r + 1, Lm, Lr);

            split(rtR[i], l, Rl, Rr);
            split(Rr, r + 1, Rm, Rr);

            int Lx, Ly, Rx, Ry;

            createPair(
                0,
                Lx,
                Ly,
                tr[Rr].sum - tr[Lr].sum
            );
            tr[Lx].pos = l;
            tr[Ly].pos = r + 1;

            createPair(
                0,
                Rx,
                Ry,
                tr[Ll].sum - tr[Rl].sum
            );
            tr[Rx].pos = l - 1;
            tr[Ry].pos = r;

            rtL[i] = mergeTree(
                mergeTree(
                    mergeTree(Ll, Lx),
                    addPosition(
                        reverseTree(Rm),
                        l + r
                    )
                ),
                mergeTree(Ly, Lr)
            );

            rtR[i] = mergeTree(
                mergeTree(
                    mergeTree(Rl, Rx),
                    addPosition(
                        reverseTree(Lm),
                        l + r
                    )
                ),
                mergeTree(Ry, Rr)
            );
        } else if (opt == 4) {
            scanf("%lld", &x);
            x ^= key;

            rtL[i] = rtL[x];
            rtR[i] = rtR[x];
        } else {
            scanf("%lld", &x);
            x ^= key;

            split(rtL[i], x + 1, Ll, Lr);
            split(rtR[i], x, Rl, Rr);

            if (tr[Ll].sum != tr[Rl].sum) {
                puts("Yes");
                ++key;
            } else {
                puts("No");
            }

            rtL[i] = rtL[i - 1];
            rtR[i] = rtR[i - 1];
        }

        if (tot >= MAXNODE) {
            fprintf(stderr, "node pool exhausted\n");
            exit(1);
        }
    }
}

int main() {
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test2.out","w",stdout);
    srand(712367821);
    int T;
    scanf("%d", &T);

	for(int i=1; i<=T; ++i){
		solveCase();
        // cout<<"finish:"<<i<<endl;
	}

    return 0;
}