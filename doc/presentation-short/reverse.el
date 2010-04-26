reverse(List) -> reverse(List, []);

reverse([Top|Rest], Result) -> reverse(Rest, [Top|Result]);
reverse([],         Result) -> Result.
