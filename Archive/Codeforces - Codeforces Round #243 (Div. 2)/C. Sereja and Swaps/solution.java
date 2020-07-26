import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ListIterator;
import java.util.AbstractList;
import java.util.InputMismatchException;
import java.util.Deque;
import java.util.NoSuchElementException;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.Collection;
import java.io.IOException;
import java.util.List;
import java.util.Comparator;
import java.util.ArrayDeque;
import java.util.Collections;
import java.util.ConcurrentModificationException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author cunbidun
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CSerejaAndSwaps solver = new CSerejaAndSwaps();
        solver.solve(1, in, out);
        out.close();
    }

    static class CSerejaAndSwaps {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int m = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            int[] b = new int[n + 1];
            if (n >= 0) System.arraycopy(a, 1, b, 1, n);
            MergeSort.sort(b, 1, n, Comparator.reverseOrder());
            int max = ArrayAlgorithm.getMax(a, 1, n);
            if (max < 0) {
                out.println(max);
                return;
            }
            int defAns = b[1];
            for (int i = 2; i <= MaxMin.Min(n, m); i++) {
                if (b[i] < 0) break;
                defAns += b[i];
            }
            SBTree<Integer>[] setB = new SBTree[n + 1];
            SBTree<Integer>[] setA = new SBTree[n + 1];
            for (int i = 1; i <= n; i++) {
                setA[i] = new SBTree<>(true);
                setB[i] = new SBTree<>(true);
            }
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    setA[i].add(a[j]);
                }
                for (int j = i - 1; j >= 1; j--) {
                    setB[i].add(a[j]);
                }
            }
            int ans = defAns;
            for (int i = 1; i <= n; i++)
                for (int j = i + m - 1; j <= n; j++) {
                    int res = 0;
                    TreeList<Integer> listIn = new TreeList<>();
                    TreeList<Integer> listOut = new TreeList<>();

                    for (int k = i; k <= j; k++) listIn.add(a[k]);
                    Collections.sort(listIn);
                    for (int k = 0; k < listIn.size(); k++)
                        if (k < m) listOut.add(listIn.get(k));
                        else
                            res += listIn.get(k);
                    for (int k = 1; k <= m; k++) {
                        if (k > setA[j].size()) break;
                        listOut.add(setA[j].getKth(setA[j].size() - k + 1));
                    }

                    for (int k = 1; k <= m; k++) {
                        if (k > setB[i].size()) break;
                        listOut.add(setB[i].getKth(setB[i].size() - k + 1));
                    }
                    listOut.sort(Collections.reverseOrder());
                    for (int k = 0; k <= MaxMin.Min(listOut.size() - 1, m - 1); k++) {
                        if (res + listOut.get(k) < res) break;
                        res += listOut.get(k);
                    }
                    ans = MaxMin.Max(ans, res);
                }
            out.println(ans);
        }

    }

    static class TreeList<E> extends AbstractList<E> {
        private TreeList.AVLNode<E> root;
        private int size;

        public TreeList() {
            super();
        }

        public TreeList(final Collection<? extends E> coll) {
            super();
            if (!coll.isEmpty()) {
                root = new TreeList.AVLNode<>(coll);
                size = coll.size();
            }
        }

        public E get(final int index) {
            return root.get(index).getValue();
        }

        public int size() {
            return size;
        }

        public Iterator<E> iterator() {
            // override to go 75% faster
            return listIterator(0);
        }

        public ListIterator<E> listIterator() {
            // override to go 75% faster
            return listIterator(0);
        }

        public ListIterator<E> listIterator(final int fromIndex) {
            return new TreeList.TreeListIterator<>(this, fromIndex);
        }

        public int indexOf(final Object object) {
            // override to go 75% faster
            if (root == null) {
                return -1;
            }
            return root.indexOf(object, root.relativePosition);
        }

        public boolean contains(final Object object) {
            return indexOf(object) >= 0;
        }

        public Object[] toArray() {
            final Object[] array = new Object[size()];
            if (root != null) {
                root.toArray(array, root.relativePosition);
            }
            return array;
        }

        public void add(final int index, final E obj) {
            modCount++;
            if (root == null) {
                root = new TreeList.AVLNode<>(index, obj, null, null);
            } else {
                root = root.insert(index, obj);
            }
            size++;
        }

        public boolean addAll(final Collection<? extends E> c) {
            if (c.isEmpty()) {
                return false;
            }
            modCount += c.size();
            final TreeList.AVLNode<E> cTree = new TreeList.AVLNode<>(c);
            root = root == null ? cTree : root.addAll(cTree, size);
            size += c.size();
            return true;
        }

        public E set(final int index, final E obj) {
            final TreeList.AVLNode<E> node = root.get(index);
            final E result = node.value;
            node.setValue(obj);
            return result;
        }

        public E remove(final int index) {
            modCount++;
            final E result = get(index);
            root = root.remove(index);
            size--;
            return result;
        }

        public void clear() {
            modCount++;
            root = null;
            size = 0;
        }

        static class AVLNode<E> {
            private TreeList.AVLNode<E> left;
            private boolean leftIsPrevious;
            private TreeList.AVLNode<E> right;
            private boolean rightIsNext;
            private int height;
            private int relativePosition;
            private E value;

            private AVLNode(final int relativePosition, final E obj,
                            final TreeList.AVLNode<E> rightFollower, final TreeList.AVLNode<E> leftFollower) {
                this.relativePosition = relativePosition;
                value = obj;
                rightIsNext = true;
                leftIsPrevious = true;
                right = rightFollower;
                left = leftFollower;
            }

            private AVLNode(final Collection<? extends E> coll) {
                this(coll.iterator(), 0, coll.size() - 1, 0, null, null);
            }

            private AVLNode(final Iterator<? extends E> iterator, final int start, final int end,
                            final int absolutePositionOfParent, final TreeList.AVLNode<E> prev, final TreeList.AVLNode<E> next) {
                final int mid = start + (end - start) / 2;
                if (start < mid) {
                    left = new TreeList.AVLNode<>(iterator, start, mid - 1, mid, prev, this);
                } else {
                    leftIsPrevious = true;
                    left = prev;
                }
                value = iterator.next();
                relativePosition = mid - absolutePositionOfParent;
                if (mid < end) {
                    right = new TreeList.AVLNode<>(iterator, mid + 1, end, mid, this, next);
                } else {
                    rightIsNext = true;
                    right = next;
                }
                recalcHeight();
            }

            E getValue() {
                return value;
            }

            void setValue(final E obj) {
                this.value = obj;
            }

            TreeList.AVLNode<E> get(final int index) {
                final int indexRelativeToMe = index - relativePosition;

                if (indexRelativeToMe == 0) {
                    return this;
                }

                final TreeList.AVLNode<E> nextNode = indexRelativeToMe < 0 ? getLeftSubTree() : getRightSubTree();
                if (nextNode == null) {
                    return null;
                }
                return nextNode.get(indexRelativeToMe);
            }

            int indexOf(final Object object, final int index) {
                if (getLeftSubTree() != null) {
                    final int result = left.indexOf(object, index + left.relativePosition);
                    if (result != -1) {
                        return result;
                    }
                }
                if (value == null ? value == object : value.equals(object)) {
                    return index;
                }
                if (getRightSubTree() != null) {
                    return right.indexOf(object, index + right.relativePosition);
                }
                return -1;
            }

            void toArray(final Object[] array, final int index) {
                array[index] = value;
                if (getLeftSubTree() != null) {
                    left.toArray(array, index + left.relativePosition);
                }
                if (getRightSubTree() != null) {
                    right.toArray(array, index + right.relativePosition);
                }
            }

            TreeList.AVLNode<E> next() {
                if (rightIsNext || right == null) {
                    return right;
                }
                return right.min();
            }

            TreeList.AVLNode<E> previous() {
                if (leftIsPrevious || left == null) {
                    return left;
                }
                return left.max();
            }

            TreeList.AVLNode<E> insert(final int index, final E obj) {
                final int indexRelativeToMe = index - relativePosition;

                if (indexRelativeToMe <= 0) {
                    return insertOnLeft(indexRelativeToMe, obj);
                }
                return insertOnRight(indexRelativeToMe, obj);
            }

            private TreeList.AVLNode<E> insertOnLeft(final int indexRelativeToMe, final E obj) {
                if (getLeftSubTree() == null) {
                    setLeft(new TreeList.AVLNode<>(-1, obj, this, left), null);
                } else {
                    setLeft(left.insert(indexRelativeToMe, obj), null);
                }

                if (relativePosition >= 0) {
                    relativePosition++;
                }
                final TreeList.AVLNode<E> ret = balance();
                recalcHeight();
                return ret;
            }

            private TreeList.AVLNode<E> insertOnRight(final int indexRelativeToMe, final E obj) {
                if (getRightSubTree() == null) {
                    setRight(new TreeList.AVLNode<>(+1, obj, right, this), null);
                } else {
                    setRight(right.insert(indexRelativeToMe, obj), null);
                }
                if (relativePosition < 0) {
                    relativePosition--;
                }
                final TreeList.AVLNode<E> ret = balance();
                recalcHeight();
                return ret;
            }

            private TreeList.AVLNode<E> getLeftSubTree() {
                return leftIsPrevious ? null : left;
            }

            private TreeList.AVLNode<E> getRightSubTree() {
                return rightIsNext ? null : right;
            }

            private TreeList.AVLNode<E> max() {
                return getRightSubTree() == null ? this : right.max();
            }

            private TreeList.AVLNode<E> min() {
                return getLeftSubTree() == null ? this : left.min();
            }

            TreeList.AVLNode<E> remove(final int index) {
                final int indexRelativeToMe = index - relativePosition;

                if (indexRelativeToMe == 0) {
                    return removeSelf();
                }
                if (indexRelativeToMe > 0) {
                    setRight(right.remove(indexRelativeToMe), right.right);
                    if (relativePosition < 0) {
                        relativePosition++;
                    }
                } else {
                    setLeft(left.remove(indexRelativeToMe), left.left);
                    if (relativePosition > 0) {
                        relativePosition--;
                    }
                }
                recalcHeight();
                return balance();
            }

            private TreeList.AVLNode<E> removeMax() {
                if (getRightSubTree() == null) {
                    return removeSelf();
                }
                setRight(right.removeMax(), right.right);
                if (relativePosition < 0) {
                    relativePosition++;
                }
                recalcHeight();
                return balance();
            }

            private TreeList.AVLNode<E> removeMin() {
                if (getLeftSubTree() == null) {
                    return removeSelf();
                }
                setLeft(left.removeMin(), left.left);
                if (relativePosition > 0) {
                    relativePosition--;
                }
                recalcHeight();
                return balance();
            }

            private TreeList.AVLNode<E> removeSelf() {
                if (getRightSubTree() == null && getLeftSubTree() == null) {
                    return null;
                }
                if (getRightSubTree() == null) {
                    if (relativePosition > 0) {
                        left.relativePosition += relativePosition;
                    }
                    left.max().setRight(null, right);
                    return left;
                }
                if (getLeftSubTree() == null) {
                    right.relativePosition += relativePosition - (relativePosition < 0 ? 0 : 1);
                    right.min().setLeft(null, left);
                    return right;
                }

                if (heightRightMinusLeft() > 0) {
                    // more on the right, so delete from the right
                    final TreeList.AVLNode<E> rightMin = right.min();
                    value = rightMin.value;
                    if (leftIsPrevious) {
                        left = rightMin.left;
                    }
                    right = right.removeMin();
                    if (relativePosition < 0) {
                        relativePosition++;
                    }
                } else {
                    // more on the left or equal, so delete from the left
                    final TreeList.AVLNode<E> leftMax = left.max();
                    value = leftMax.value;
                    if (rightIsNext) {
                        right = leftMax.right;
                    }
                    final TreeList.AVLNode<E> leftPrevious = left.left;
                    left = left.removeMax();
                    if (left == null) {
                        // special case where left that was deleted was a double link
                        // only occurs when height difference is equal
                        left = leftPrevious;
                        leftIsPrevious = true;
                    }
                    if (relativePosition > 0) {
                        relativePosition--;
                    }
                }
                recalcHeight();
                return this;
            }

            private TreeList.AVLNode<E> balance() {
                switch (heightRightMinusLeft()) {
                    case 1:
                    case 0:
                    case -1:
                        return this;
                    case -2:
                        if (left.heightRightMinusLeft() > 0) {
                            setLeft(left.rotateLeft(), null);
                        }
                        return rotateRight();
                    case 2:
                        if (right.heightRightMinusLeft() < 0) {
                            setRight(right.rotateRight(), null);
                        }
                        return rotateLeft();
                    default:
                        throw new RuntimeException("tree inconsistent!");
                }
            }

            private int getOffset(final TreeList.AVLNode<E> node) {
                if (node == null) {
                    return 0;
                }
                return node.relativePosition;
            }

            private int setOffset(final TreeList.AVLNode<E> node, final int newOffest) {
                if (node == null) {
                    return 0;
                }
                final int oldOffset = getOffset(node);
                node.relativePosition = newOffest;
                return oldOffset;
            }

            private void recalcHeight() {
                height = Math.max(
                        getLeftSubTree() == null ? -1 : getLeftSubTree().height,
                        getRightSubTree() == null ? -1 : getRightSubTree().height) + 1;
            }

            private int getHeight(final TreeList.AVLNode<E> node) {
                return node == null ? -1 : node.height;
            }

            private int heightRightMinusLeft() {
                return getHeight(getRightSubTree()) - getHeight(getLeftSubTree());
            }

            private TreeList.AVLNode<E> rotateLeft() {
                final TreeList.AVLNode<E> newTop = right; // can't be faedelung!
                final TreeList.AVLNode<E> movedNode = getRightSubTree().getLeftSubTree();

                final int newTopPosition = relativePosition + getOffset(newTop);
                final int myNewPosition = -newTop.relativePosition;
                final int movedPosition = getOffset(newTop) + getOffset(movedNode);

                setRight(movedNode, newTop);
                newTop.setLeft(this, null);

                setOffset(newTop, newTopPosition);
                setOffset(this, myNewPosition);
                setOffset(movedNode, movedPosition);
                return newTop;
            }

            private TreeList.AVLNode<E> rotateRight() {
                final TreeList.AVLNode<E> newTop = left;
                final TreeList.AVLNode<E> movedNode = getLeftSubTree().getRightSubTree();

                final int newTopPosition = relativePosition + getOffset(newTop);
                final int myNewPosition = -newTop.relativePosition;
                final int movedPosition = getOffset(newTop) + getOffset(movedNode);

                setLeft(movedNode, newTop);
                newTop.setRight(this, null);

                setOffset(newTop, newTopPosition);
                setOffset(this, myNewPosition);
                setOffset(movedNode, movedPosition);
                return newTop;
            }

            private void setLeft(final TreeList.AVLNode<E> node, final TreeList.AVLNode<E> previous) {
                leftIsPrevious = node == null;
                left = leftIsPrevious ? previous : node;
                recalcHeight();
            }

            private void setRight(final TreeList.AVLNode<E> node, final TreeList.AVLNode<E> next) {
                rightIsNext = node == null;
                right = rightIsNext ? next : node;
                recalcHeight();
            }

            private TreeList.AVLNode<E> addAll(TreeList.AVLNode<E> otherTree, final int currentSize) {
                final TreeList.AVLNode<E> maxNode = max();
                final TreeList.AVLNode<E> otherTreeMin = otherTree.min();

                // We need to efficiently merge the two AVL trees while keeping them
                // balanced (or nearly balanced). To do this, we take the shorter
                // tree and combine it with a similar-height subtree of the taller
                // tree. There are two symmetric cases:
                //   * this tree is taller, or
                //   * otherTree is taller.
                if (otherTree.height > height) {
                    // CASE 1: The other tree is taller than this one. We will thus
                    // merge this tree into otherTree.

                    // STEP 1: Remove the maximum element from this tree.
                    final TreeList.AVLNode<E> leftSubTree = removeMax();

                    // STEP 2: Navigate left from the root of otherTree until we
                    // contains a subtree, s, that is no taller than me. (While we are
                    // navigating left, we store the nodes we encounter in a stack
                    // so that we can re-balance them in step 4.)
                    final Deque<TreeList.AVLNode<E>> sAncestors = new ArrayDeque<>();
                    TreeList.AVLNode<E> s = otherTree;
                    int sAbsolutePosition = s.relativePosition + currentSize;
                    int sParentAbsolutePosition = 0;
                    while (s != null && s.height > getHeight(leftSubTree)) {
                        sParentAbsolutePosition = sAbsolutePosition;
                        sAncestors.push(s);
                        s = s.left;
                        if (s != null) {
                            sAbsolutePosition += s.relativePosition;
                        }
                    }

                    // STEP 3: Replace s with a newly constructed subtree whose root
                    // is maxNode, whose left subtree is leftSubTree, and whose right
                    // subtree is s.
                    maxNode.setLeft(leftSubTree, null);
                    maxNode.setRight(s, otherTreeMin);
                    if (leftSubTree != null) {
                        leftSubTree.max().setRight(null, maxNode);
                        leftSubTree.relativePosition -= currentSize - 1;
                    }
                    if (s != null) {
                        s.min().setLeft(null, maxNode);
                        s.relativePosition = sAbsolutePosition - currentSize + 1;
                    }
                    maxNode.relativePosition = currentSize - 1 - sParentAbsolutePosition;
                    otherTree.relativePosition += currentSize;

                    // STEP 4: Re-balance the tree and recalculate the heights of s's ancestors.
                    s = maxNode;
                    while (!sAncestors.isEmpty()) {
                        final TreeList.AVLNode<E> sAncestor = sAncestors.pop();
                        sAncestor.setLeft(s, null);
                        s = sAncestor.balance();
                    }
                    return s;
                }
                otherTree = otherTree.removeMin();

                final Deque<TreeList.AVLNode<E>> sAncestors = new ArrayDeque<>();
                TreeList.AVLNode<E> s = this;
                int sAbsolutePosition = s.relativePosition;
                int sParentAbsolutePosition = 0;
                while (s != null && s.height > getHeight(otherTree)) {
                    sParentAbsolutePosition = sAbsolutePosition;
                    sAncestors.push(s);
                    s = s.right;
                    if (s != null) {
                        sAbsolutePosition += s.relativePosition;
                    }
                }

                otherTreeMin.setRight(otherTree, null);
                otherTreeMin.setLeft(s, maxNode);
                if (otherTree != null) {
                    otherTree.min().setLeft(null, otherTreeMin);
                    otherTree.relativePosition++;
                }
                if (s != null) {
                    s.max().setRight(null, otherTreeMin);
                    s.relativePosition = sAbsolutePosition - currentSize;
                }
                otherTreeMin.relativePosition = currentSize - sParentAbsolutePosition;

                s = otherTreeMin;
                while (!sAncestors.isEmpty()) {
                    final TreeList.AVLNode<E> sAncestor = sAncestors.pop();
                    sAncestor.setRight(s, null);
                    s = sAncestor.balance();
                }
                return s;
            }

        }

        static class TreeListIterator<E> implements ListIterator<E>, OrderedIterator<E> {
            private final TreeList<E> parent;
            private TreeList.AVLNode<E> next;
            private int nextIndex;
            private TreeList.AVLNode<E> current;
            private int currentIndex;
            private int expectedModCount;

            private TreeListIterator(final TreeList<E> parent, final int fromIndex) throws IndexOutOfBoundsException {
                super();
                this.parent = parent;
                this.expectedModCount = parent.modCount;
                this.next = parent.root == null ? null : parent.root.get(fromIndex);
                this.nextIndex = fromIndex;
                this.currentIndex = -1;
            }

            private void checkModCount() {
                if (parent.modCount != expectedModCount) {
                    throw new ConcurrentModificationException();
                }
            }

            public boolean hasNext() {
                return nextIndex < parent.size();
            }

            public E next() {
                checkModCount();
                if (!hasNext()) {
                    throw new NoSuchElementException("No element at index " + nextIndex + ".");
                }
                if (next == null) {
                    next = parent.root.get(nextIndex);
                }
                final E value = next.getValue();
                current = next;
                currentIndex = nextIndex++;
                next = next.next();
                return value;
            }

            public boolean hasPrevious() {
                return nextIndex > 0;
            }

            public E previous() {
                checkModCount();
                if (!hasPrevious()) {
                    throw new NoSuchElementException("Already at start of list.");
                }
                if (next == null) {
                    next = parent.root.get(nextIndex - 1);
                } else {
                    next = next.previous();
                }
                final E value = next.getValue();
                current = next;
                currentIndex = --nextIndex;
                return value;
            }

            public int nextIndex() {
                return nextIndex;
            }

            public int previousIndex() {
                return nextIndex() - 1;
            }

            public void remove() {
                checkModCount();
                if (currentIndex == -1) {
                    throw new IllegalStateException();
                }
                parent.remove(currentIndex);
                if (nextIndex != currentIndex) {
                    // remove() following next()
                    nextIndex--;
                }
                // the AVL node referenced by next may have become stale after a remove
                // reset it now: will be retrieved by next call to next()/previous() via nextIndex
                next = null;
                current = null;
                currentIndex = -1;
                expectedModCount++;
            }

            public void set(final E obj) {
                checkModCount();
                if (current == null) {
                    throw new IllegalStateException();
                }
                current.setValue(obj);
            }

            public void add(final E obj) {
                checkModCount();
                parent.add(nextIndex, obj);
                current = null;
                currentIndex = -1;
                nextIndex++;
                expectedModCount++;
            }

        }

    }

    static class ArrayAlgorithm {
        public static int getMax(int[] array, int stIndex, int enIndex) {
            int max = array[stIndex];
            for (int i = stIndex; i <= enIndex; i++) {
                max = MaxMin.Max(max, array[i]);
            }
            return max;
        }

    }

    static interface OrderedIterator<E> extends Iterator<E> {
    }

    static class SBTree<T extends Comparable<T>> {
        private Node<T> root;
        private boolean isMultiSet;

        public SBTree(boolean isMultiSet) {
            root = new Node<>();
            this.isMultiSet = isMultiSet;
        }

        public int size() {
            return root.size;
        }

        private Node<T> rotate(Node<T> a, boolean flag) {
            int d = 0;
            if (flag) d = 1;
            Node<T> b = a.ch[1 - d];
            a.ch[1 - d] = b.ch[d];
            b.ch[d] = a;
            b.size = a.size;
            a.size = a.ch[0].size + a.ch[1].size + 1;
            return b;
        }

        private Node<T> maintain(Node<T> n, boolean flag) {
            if (n.size == 0) return n;
            int d = 0;
            if (flag) d = 1;
            if (n.ch[d].size > 0 && n.ch[d].ch[d].size > n.ch[1 - d].size) {
                n = rotate(n, !flag);
            } else if (n.ch[d].size > 0 && n.ch[d].ch[1 - d].size > n.ch[1 - d].size) {
                n.ch[d] = rotate(n.ch[d], flag);
                n = rotate(n, !flag);
            } else
                return n;
            n.ch[1] = maintain(n.ch[1], true);
            n.ch[0] = maintain(n.ch[0], false);
            n = maintain(n, true);
            n = maintain(n, false);
            return n;
        }

        private Node<T> add(Node<T> n, T key) {
            if (n.size == 0) {
                n = new Node<>(key);
                return n;
            } else {
                ++n.size;
                int flag = n.key.compareTo(key);
                int d = 0;
                if (flag < 0) d = 1;
                n.ch[d] = add(n.ch[d], key);
                n = maintain(n, flag < 0);
            }
            return n;
        }

        public void add(T key) {
            if (!contains(key) || isMultiSet) root = add(root, key);
        }

        public boolean contains(T key) {
            Node<T> o = root;
            while (o.size > 0 && !o.key.equals(key)) {
                int flag = o.key.compareTo(key);
                int d = 0;
                if (flag < 0) d = 1;
                o = o.ch[d];
            }
            return o.size > 0;
        }

        public T getKth(int key) {
            for (Node<T> cur = root; ; ) {
                if (key <= cur.ch[0].size)
                    cur = cur.ch[0];
                else if (key == cur.ch[0].size + 1)
                    return cur.key;
                else {
                    key -= cur.ch[0].size + 1;
                    cur = cur.ch[1];
                }
            }
        }

        private class Node<T> {
            Node<T>[] ch = new Node[2];
            T key;
            int size;

            Node(T key) {
                this.key = key;
                this.size = 1;
                ch[1] = ch[0] = new Node<>();
            }

            Node() {
                key = null;
                size = 0;
            }

        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
        }

        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public int[] nextIntArray(int length, int stIndex) {
            int[] arr = new int[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class MergeSort {
        private static final int CUTOFF = 7;

        private MergeSort() {
        }

        private static void swap(Object[] a, int i, int j) {
            Object swap = a[i];
            a[i] = a[j];
            a[j] = swap;
        }

        private static boolean less(Object a, Object b, Comparator comparator) {
            return comparator.compare(a, b) < 0;
        }

        private static void merge(Object[] src, Object[] dst, int lo, int mid, int hi, Comparator comparator) {
            int i = lo, j = mid + 1;
            for (int k = lo; k <= hi; k++) {
                if (i > mid) dst[k] = src[j++];
                else if (j > hi) dst[k] = src[i++];
                else if (less(src[j], src[i], comparator)) dst[k] = src[j++];
                else dst[k] = src[i++];
            }
        }

        private static void sort(Object[] src, Object[] dst, int lo, int hi, Comparator comparator) {
            if (hi <= lo + CUTOFF) {
                insertionSort(dst, lo, hi, comparator);
                return;
            }
            int mid = lo + (hi - lo) / 2;
            sort(dst, src, lo, mid, comparator);
            sort(dst, src, mid + 1, hi, comparator);
            if (!less(src[mid + 1], src[mid], comparator)) {
                System.arraycopy(src, lo, dst, lo, hi - lo + 1);
                return;
            }

            merge(src, dst, lo, mid, hi, comparator);
        }

        private static void insertionSort(Object[] a, int lo, int hi, Comparator comparator) {
            for (int i = lo; i <= hi; i++)
                for (int j = i; j > lo && less(a[j], a[j - 1], comparator); j--)
                    swap(a, j, j - 1);
        }

        public static void sort(Object[] a, int lo, int hi, Comparator comparator) {
            Object[] aux = a.clone();
            sort(aux, a, lo, hi, comparator);
        }

        public static int[] sort(int[] input, int lo, int hi, Comparator comparator) {
            Integer[] a = new Integer[input.length];
            for (int ctr = 0; ctr < input.length; ctr++) a[ctr] = input[ctr];
            sort(a, lo, hi, comparator);
            for (int ctr = 0; ctr < a.length; ctr++) input[ctr] = a[ctr];
            return input;
        }

    }
}