use proconio::input;
fn main() {
    input! {
        n: i64,
        mut a: [i64;n],
    }

    let mut mem = -1;
    let mut cnt = 1;
    let mut ans = 0;

    for i in a {
        if i != mem {
            mem = i;
            ans += cnt/2;
            cnt = 1;
        }else {
            cnt+=1;
        }
    }
    ans += cnt/2;

    println!("{}",ans);
}

