function D(a, b, c)
	return b*b - 4 * a * c
end

function linear(a, b)
	if(a == 0 && b == 0)
		return "infinity"
	elseif a == 0
		return "nan"
	else
		return -b/a
	end
end



function quadrate(a, b, c)
	dkr = D(a, b, c)
	if dkr < 0
		return "none"
	elseif dkr == 0
		return -b / 2*a
	else 
		if a !== 0
			x1 = -b - sqrt(dkr) / 2*a
			x2 = -b + sqrt(dkr) / 2*a
			return x1,x2
		else
			return linear(b, c)
		end
	end
end


println(quadrate(1, 4, 4))
