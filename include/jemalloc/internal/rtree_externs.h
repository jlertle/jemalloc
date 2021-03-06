#ifndef JEMALLOC_INTERNAL_RTREE_EXTERNS_H
#define JEMALLOC_INTERNAL_RTREE_EXTERNS_H

bool rtree_new(rtree_t *rtree, unsigned bits);
#ifdef JEMALLOC_JET
typedef rtree_elm_t *(rtree_node_alloc_t)(tsdn_t *, rtree_t *, size_t);
extern rtree_node_alloc_t *rtree_node_alloc;
typedef void (rtree_node_dalloc_t)(tsdn_t *, rtree_t *, rtree_elm_t *);
extern rtree_node_dalloc_t *rtree_node_dalloc;
void	rtree_delete(tsdn_t *tsdn, rtree_t *rtree);
#endif
rtree_elm_t	*rtree_subtree_read_hard(tsdn_t *tsdn, rtree_t *rtree,
    unsigned level);
rtree_elm_t	*rtree_child_read_hard(tsdn_t *tsdn, rtree_t *rtree,
    rtree_elm_t *elm, unsigned level);
void	rtree_elm_witness_acquire(tsdn_t *tsdn, const rtree_t *rtree,
    uintptr_t key, const rtree_elm_t *elm);
void	rtree_elm_witness_access(tsdn_t *tsdn, const rtree_t *rtree,
    const rtree_elm_t *elm);
void	rtree_elm_witness_release(tsdn_t *tsdn, const rtree_t *rtree,
    const rtree_elm_t *elm);

#endif /* JEMALLOC_INTERNAL_RTREE_EXTERNS_H */
