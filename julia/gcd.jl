function gcd(a, b)
	if b == 0
		return a
	else
		return gcd(b, a % b)
	end
end


println(gcd(6, 36))
