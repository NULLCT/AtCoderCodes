use proconio::{fastout, input};

#[fastout]
fn main() {
  input! {
    n:i64,
    a:i64,
    b:i64,
  }
  println!("{}",if (b-a) % 2 == 0 { "Alice" }  else  { "Borys" });
}

