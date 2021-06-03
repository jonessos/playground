mod factorial;

fn main()
{
	let n: u64 = 4;
	println!("{:#?}! = {:#?}", n, factorial::factorial(n));
}
