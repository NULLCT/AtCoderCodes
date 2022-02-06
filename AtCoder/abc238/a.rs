use proconio::input;

fn main() {
    input!{
        n: i64
    }

    println!("{}",match n {
        1 => "Yes",
        2 => "No",
        3 => "No",
        4 => "No",
        _ => "Yes",
    });
}

