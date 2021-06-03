mod lib;

fn main()
{
	let _var :u64 = lib::sub();

	println!("return = {:#x}", _var);

	lib::do_loop();
}
