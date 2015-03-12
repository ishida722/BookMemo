void *
bsearch(key, base0, nmemb, size, compar)
    register const void *key;
    const void *base0;
    size_t nmemb;
    register size_t size;
    register int (*compar) __P((const void *, const void *));
{
	register const char *base = base0;
	for (lim = nmemb ; lim != 0;) {
		p = base + lim / 2;
		cmp = (*compar)(key, p);
		if (cmp == 0)
			return ((void *)p);
		if (cmp > 0) {
			/*Key > p: move right*/
			base = p + 1;
			lim--;
		} /* else move left */
		lim /= 2;
	}
	return (NULL);
}
