import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.NoSuchElementException;
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
        CSoldierAndCards solver = new CSoldierAndCards();
        solver.solve(1, in, out);
        out.close();
    }

    static class CSoldierAndCards {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            Queue<Integer> q1 = new Queue<>();
            Queue<Integer> q2 = new Queue<>();
            for (int i = 1; i <= m; i++) {
                q1.enQueue(in.nextInt());
            }
            m = in.nextInt();
            for (int i = 1; i <= m; i++) {
                q2.enQueue(in.nextInt());
            }
            int ans = 0;
            while (!q1.isEmpty() && !q2.isEmpty()) {
                int c1 = q1.deQueue();
                int c2 = q2.deQueue();
                ans++;
                if (c1 > c2) {
                    q1.enQueue(c2);
                    q1.enQueue(c1);
                } else {
                    q2.enQueue(c1);
                    q2.enQueue(c2);
                }
                if (ans == 10000000) {
                    out.println(-1);
                    return;
                }
            }
            out.print(ans + " ");
            if (!q1.isEmpty()) out.println(1);
            else out.println(2);
        }

    }

    static class Queue<Item> implements Iterable<Item> {
        private int n;
        private Node first;
        private Node last;

        public Queue() {
            first = null;
            last = null;
            n = 0;
            assert check();
        }

        public boolean isEmpty() {
            return first == null;
        }

        public void enQueue(Item item) {
            Node oldLast = last;
            last = new Node();
            last.item = item;
            last.next = null;
            if (isEmpty()) first = last;
            else oldLast.next = last;
            n++;
            assert check();
        }

        public Item deQueue() {
            if (isEmpty()) throw new NoSuchElementException("Queue underflow");
            Item item = first.item;
            first = first.next;
            n--;
            if (isEmpty()) last = null;   // to avoid loitering
            assert check();
            return item;
        }

        public String toString() {
            StringBuilder s = new StringBuilder();
            for (Item item : this)
                s.append(item).append(" ");
            return s.toString();
        }

        private boolean check() {
            if (n < 0) {
                return false;
            } else if (n == 0) {
                if (first != null) return false;
                return last == null;
            } else if (n == 1) {
                if (first == null || last == null) return false;
                if (first != last) return false;
                return first.next == null;
            } else {
                if (first == null || last == null) return false;
                if (first == last) return false;
                if (first.next == null) return false;
                if (last.next != null) return false;

                // check internal consistency of instance variable n
                int numberOfNodes = 0;
                for (Node x = first; x != null && numberOfNodes <= n; x = x.next) {
                    numberOfNodes++;
                }
                if (numberOfNodes != n) return false;

                // check internal consistency of instance variable last
                Node lastNode = first;
                while (lastNode.next != null) {
                    lastNode = lastNode.next;
                }
                return last == lastNode;
            }

        }

        public Iterator<Item> iterator() {
            return new ListIterator();
        }

        private class Node {
            private Item item;
            private Node next;

        }

        private class ListIterator implements Iterator<Item> {
            private Node current = first;

            public boolean hasNext() {
                return current != null;
            }

            public void remove() {
                throw new UnsupportedOperationException();
            }

            public Item next() {
                if (!hasNext()) throw new NoSuchElementException();
                Item item = current.item;
                current = current.next;
                return item;
            }

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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}