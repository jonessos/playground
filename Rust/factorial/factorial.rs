pub fn factorial(n: u64) -> u64
{
	let mut factorial: u64 = 1;

	for idx in 1..n+1 {
		factorial *= idx;
	}

	return factorial;
}
