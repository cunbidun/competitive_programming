import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
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
        CBeautifulLyrics solver = new CBeautifulLyrics();
        solver.solve(1, in, out);
        out.close();
    }

    static class CBeautifulLyrics {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            String[] s = new String[n + 1];
            boolean[] check = new boolean[n + 1];
            ArrayList<PairSI>[] list = new ArrayList[5 * 1000010];
            ArrayList<String>[] canfirst = new ArrayList[1000010];
            ArrayList<Pair<String, String>> second = new ArrayList<>();
            ArrayList<Pair<String, String>> first = new ArrayList<>();
            for (int i = 1; i <= 5 * 1000001; i++) list[i] = new ArrayList<>();
            for (int i = 1; i <= 1000001; i++) canfirst[i] = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                s[i] = in.nextString();
                int tmp = count(s[i]);
                char tmpc = last(s[i]);
                if (tmpc == 'a') {
                    if (list[tmp].isEmpty())
                        list[tmp].add(new PairSI(s[i], i));
                    else {
                        second.add(new Pair<>(list[tmp].get(0).first, s[i]));
                        check[i] = true;
                        check[list[tmp].get(0).second] = true;
                        list[tmp].clear();
                    }
                }
                if (tmpc == 'e') {
                    if (list[tmp + 1000000].isEmpty())
                        list[tmp + 1000000].add(new PairSI(s[i], i));
                    else {
                        second.add(new Pair<>(list[tmp + 1000000].get(0).first, s[i]));
                        check[i] = true;
                        check[list[tmp + 1000000].get(0).second] = true;
                        list[tmp + 1000000].clear();
                    }
                }
                if (tmpc == 'i') {
                    if (list[tmp + 2000000].isEmpty())
                        list[tmp + 2000000].add(new PairSI(s[i], i));
                    else {
                        second.add(new Pair<>(list[tmp + 2000000].get(0).first, s[i]));
                        check[i] = true;
                        check[list[tmp + 2000000].get(0).second] = true;
                        list[tmp + 2000000].clear();
                    }
                }
                if (tmpc == 'o') {
                    if (list[tmp + 3000000].isEmpty())
                        list[tmp + 3000000].add(new PairSI(s[i], i));
                    else {
                        second.add(new Pair<>(list[tmp + 3000000].get(0).first, s[i]));
                        check[i] = true;
                        check[list[tmp + 3000000].get(0).second] = true;
                        list[tmp + 3000000].clear();
                    }
                }
                if (tmpc == 'u') {
                    if (list[tmp + 4000000].isEmpty())
                        list[tmp + 4000000].add(new PairSI(s[i], i));
                    else {
                        second.add(new Pair<>(list[tmp + 4000000].get(0).first, s[i]));
                        check[i] = true;
                        check[list[tmp + 4000000].get(0).second] = true;
                        list[tmp + 4000000].clear();
                    }
                }

            }

            for (int i = 1; i <= n; i++)
                if (!check[i]) {
                    int tmp = count(s[i]);
                    if (canfirst[tmp].isEmpty())
                        canfirst[tmp].add(s[i]);
                    else {
                        first.add(new Pair<>(canfirst[tmp].get(0), s[i]));
                        canfirst[tmp].clear();
                    }
                }

            out.println(MaxMin.Min((first.size() + second.size()) / 2, second.size()));
            int pos = 0;
            for (int i = 0; i < first.size(); i++) {
                if (pos < second.size()) {
                    out.println(first.get(i).first + " " + second.get(pos).first);
                    out.println(first.get(i).second + " " + second.get(pos).second);
                    pos++;
                }
            }

            for (int i = pos; i + 1 < second.size(); i += 2) {
                out.println(second.get(i).first + " " + second.get(i + 1).first);
                out.println(second.get(i).second + " " + second.get(i + 1).second);

            }
        }

        private int count(String s) {
            return StringUtil.count(s, 'a') + StringUtil.count(s, 'e') + StringUtil.count(s, 'o') + StringUtil.count(s, 'i') + StringUtil.count(s, 'u');
        }

        private char last(String s) {
            for (int i = s.length() - 1; i >= 0; i--) {
                if (s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'o' || s.charAt(i) == 'i' || s.charAt(i) == 'u')
                    return s.charAt(i);
            }
            return 'x';
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

        public String nextString() {
            int c;
            while (isSpaceChar(c = read())) ;
            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);
            while (!isSpaceChar(c = read()))
                result.appendCodePoint(c);
            return result.toString();
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
        }

    }

    static class PairSI implements Comparable<PairSI> {
        public String first;
        public int second;

        public PairSI(String first, int second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            PairSI pair = (PairSI) o;

            return first.equals(pair.first) && second == pair.second;
        }

        public String toString() {
            return "(" + first + "," + second + ")";
        }

        public int compareTo(PairSI o) {
            int value = first.compareTo(o.first);
            if (value != 0) {
                return value;
            }
            return Integer.compare(second, o.second);
        }

    }

    static class Pair<U extends Comparable<U>, V extends Comparable<V>> implements Comparable<Pair<U, V>> {
        public U first;
        public V second;

        public Pair(U first, V second) {
            this.first = first;
            this.second = second;
        }

        public String toString() {
            return "(" + first + "," + second + ")";
        }

        public int compareTo(Pair<U, V> o) {
            int value = first.compareTo(o.first);
            if (value != 0) {
                return value;
            }
            return second.compareTo(o.second);
        }

    }

    static class StringUtil {
        public static int count(String S, int stIndex, int enIndex, char c) {
            int cnt = 0;
            for (int i = stIndex; i <= enIndex; i++) {
                if (S.charAt(i) == c) cnt++;
            }
            return cnt;
        }

        public static int count(String S, char c) {
            return count(S, 0, S.length() - 1, c);
        }

    }
}