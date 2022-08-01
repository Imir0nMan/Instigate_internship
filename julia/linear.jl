function linear(a, b)
	if(a == 0 && b == 0)
		return "infinity"
	elseif a == 0
		return "nan"
	else
		return -b/a
	end
end


println(linear(0, 0))

