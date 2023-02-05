use std::{
    collections::VecDeque,
    fmt,
    io::{self, BufRead},
    str::FromStr,
};

struct Scanner {
    tokens: VecDeque<String>,
}

impl Scanner {
    pub fn new() -> Self {
        let stdin = io::stdin();
        let mut tokens = VecDeque::new();
        for line in stdin.lock().lines() {
            for token in line.unwrap().split_ascii_whitespace() {
                tokens.push_back(token.to_owned());
            }
        }
        Self { tokens }
    }

    pub fn next<T: FromStr>(&mut self) -> T
    where
        <T as FromStr>::Err: fmt::Debug,
    {
        T::from_str(&self.tokens.pop_front().unwrap()).unwrap()
    }
}

fn main() {
    let mut input = Scanner::new();
    let n: i32 = input.next();
    let b: Vec<i64> = (0..n).map(|_| input.next()).collect();
    let a: Vec<i64> = (0..n).map(|_| input.next()).collect();
    let mut diff_odd: Vec<i64> = Vec::new();
    let mut diff_even: Vec<i64> = Vec::new();
    let mut ans: i64 = 0;
    for i in 0..n as usize {
        ans += a[i];
        if i % 2 == 0 {
            diff_even.push(b[i] - a[i]);
        } else {
            diff_odd.push(b[i] - a[i]);
        }
    }
    diff_odd.sort();
    diff_odd.reverse();
    diff_even.sort();
    diff_even.reverse();
    for i in 0..(n / 2) as usize {
        if diff_odd[i] + diff_even[i] > 0 {
            ans += diff_odd[i] + diff_even[i];
        }
    }
    println!("{}\n", ans);
}
