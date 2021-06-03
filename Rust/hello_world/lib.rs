pub fn sub() -> u64
{
	println!("Hello, world!");
	return 0xf7deadbeef;
}

pub fn do_loop()
{
	let mut var: u128 = 0;

	loop {
		println!("{:#x}", var);
		var += 1;
	}
}
