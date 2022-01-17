/*
 * compare two xml files
 *
 * Copyright (C) 2021 Olaf Kirch <okir@suse.de>
 */

#include <stdbool.h>
#include <xml.h>

static inline bool
do_open_xml(const char *path, xml_document_t **doc_ret)
{
	*doc_ret = xml_document_read(path);
	if (*doc_ret == NULL) {
		fprintf(stderr, "Unable to open %s: %m\n", path);
		return false;
	}

	return true;
}

static void
print_mismatch(const xml_node_t *node1, const xml_node_t *node2, const char *fmt, ...)
{
	va_list ap;

	va_start(fmt, ap);
	fprintf(stderr, "XML mismatch: ");
	vfprintf(stderr, fmt, ap);
	fputc('\n', stderr);
	fprintf(stderr, "  %s vs %s", xml_node_location(node1), xml_node_location(node2));
	va_end(ap);
}

static bool
do_compare(const char *template_path, const char *file1_path, const char *file2_path)
{
	xml_document_t *template;
	xml_document_t *doc1;
	xml_document_t *doc2;

	if (!do_open_xml(template_path, &template)
	 || !do_open_xml(file1_path, &doc1)
	 || !do_open_xml(file2_path, &doc2))
		return false;

	
}
