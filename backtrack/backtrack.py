final_result = []

all_girls = [ "g00", "g01", "g02", "g03", "g04", "g05", "g06", "g07", "g08", "g09", "g10", "g11", "g12", "g13", "g14"]
all_triples =[]

def gen_all_triples():
	for i in range(15):
		for j in range(i+1,15):
			for k in range(j+1,15):
				all_triples.append((i,j,k))

been_together={}

def add_triple(triple):
	(a,b,c) = triple
	been_together[(a,b)] = True
	been_together[(a,c)] = True
	been_together[(b,c)] = True

def rem_triple(triple):
	(a,b,c) = triple
	del been_together[(a,b)]
	del been_together[(a,c)]
	del been_together[(b,c)]

def has_any_been_together(triple):
	(a,b,c) = triple
	return (been_together.has_key((a,b)) or been_together.has_key((a,c)) or been_together.has_key((b,c)))


def add_picked_triple(picked_list, triple):
	(a,b,c) = triple
	picked_list[a] = True
	picked_list[b] = True
	picked_list[c] = True

def rem_picked_triple(picked_list, triple):
	(a,b,c) = triple
	del picked_list[a]
	del picked_list[b]
	del picked_list[c]

def has_any_been_picked(picked_list, triple):
	(a,b,c) = triple
	return (picked_list.has_key(a) or picked_list.has_key(b) or picked_list.has_key(c))


def pick_for_day(day_num):
	picked_today = {}
	for a in all_triples:
		if (has_any_been_picked(picked_today,a) or has_any_been_together(a)):
			continue
		add_picked_triple(picked_today,a)
		add_triple(a)

		for b in all_triples:
			if (has_any_been_picked(picked_today,b) or has_any_been_together(b)):
				continue
			add_picked_triple(picked_today,b)
			add_triple(b)

			for c in all_triples:
				if (has_any_been_picked(picked_today,c) or has_any_been_together(c)):
					continue
				add_picked_triple(picked_today,c)
				add_triple(c)

				for d in all_triples:
					if (has_any_been_picked(picked_today,d) or has_any_been_together(d)):
						continue
					add_picked_triple(picked_today,d)
					add_triple(d)

					for e in all_triples:
						if (has_any_been_picked(picked_today,e) or has_any_been_together(e)):
							continue
						add_picked_triple(picked_today,e)
						add_triple(e)
						res = [True]
						if (day_num < 7):
							res = pick_for_day(day_num+1)
						if (res[0] == True):
							newres = [True,(a,b,c,d,e)]
							newres.extend(res[1:])
							return newres
						else:
							# print "---backtrack---", day_num
							pass
						rem_picked_triple(picked_today,e)
						rem_triple(e)
					rem_picked_triple(picked_today,d)
					rem_triple(d)
				rem_picked_triple(picked_today,c)
				rem_triple(c)
			rem_picked_triple(picked_today,b)
			rem_triple(b)
		rem_picked_triple(picked_today,a)
		rem_triple(a)
	print "Failure at day", day_num
	return([False])

gen_all_triples()
res = pick_for_day(1)
res = res[1:]
for x in res:
	print x
Status API Training Shop Blog About
