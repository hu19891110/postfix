/*++
/* NAME
/*	postconf 1
/* SUMMARY
/*	Postfix configuration utility
/* SYNOPSIS
/* .fi
/*	\fBpostconf\fR [\fB-dhmlnv\fR] [\fB-c \fIconfig_dir\fR] 
/*	[\fIparameter ...\fR]
/*
/*	\fBpostconf\fR [\fB-ev\fR] [\fB-c \fIconfig_dir\fR]
/*	[\fIparameter=value ...\fR]
/* DESCRIPTION
/*	The \fBpostconf\fR command prints the actual value of
/*	\fIparameter\fR (all known parameters by default) one
/*	parameter per line, changes its value, or prints other
/*	information about the Postfix mail system.
/*
/*	Options:
/* .IP "\fB-c \fIconfig_dir\fR"
/*	The \fBmain.cf\fR configuration file is in the named directory
/*	instead of the default configuration directory.
/* .IP \fB-d\fR
/*	Print default parameter settings instead of actual settings.
/* .IP \fB-e\fR
/*	Edit the \fBmain.cf\fR configuration file. The file is copied
/*	to a temporary file then renamed into place. Parameters and
/*	values are specified on the command line. Use quotes in order
/*	to protect shell metacharacters and whitespace.
/* .IP \fB-h\fR
/*	Show parameter values only, not the ``name = '' label
/*	that normally precedes the value.
/* .IP \fB-l\fR
/*	List the names of all supported mailbox locking methods.
/*	Postfix supports the following methods:
/* .RS
/* .IP \fBflock\fR
/*	A kernel-based advisory locking method for local files only.
/*	This locking method is available only on systems with a BSD
/*	compatible library.
/* .IP \fBfcntl\fR
/*	A kernel-based advisory locking method for local and remote files.
/* .IP \fBdotlock\fR
/*	An application-level locking method. An application locks a file
/*	named \fIfilename\fR by creating a file named \fIfilename\fB.lock\fR.
/*	The application is expected to remove its own lock file, as well as
/*	stale lock files that were left behind after abnormal termination.
/* .RE
/* .IP \fB-m\fR
/*	List the names of all supported lookup table types. Postfix
/*	lookup tables are specified as \fItype\fB:\fIname\fR, where
/*	\fItype\fR is one of the types listed below. The table \fIname\fR
/*	syntax depends on the lookup table type.
/* .RS
/* .IP \fBbtree\fR
/*	A sorted, balanced tree structure.
/*	This is available only on systems with support for Berkeley DB
/*	databases.
/* .IP \fBcidr\fR
/*	A table that associates values with Classless Inter-Domain Routing
/*	(CIDR) patterns. This is described in \fBcidr_table\fR(5).
/* .IP \fBdbm\fR
/*	An indexed file type based on hashing.
/*	This is available only on systems with support for DBM databases.
/* .IP \fBenviron\fR
/*	The UNIX process environment array. The lookup key is the variable
/*	name. Originally implemented for testing, someone may find this
/*	useful someday.
/* .IP \fBhash\fR
/*	An indexed file type based on hashing.
/*	This is available only on systems with support for Berkeley DB
/*	databases.
/* .IP "\fBldap\fR (read-only)"
/*	Perform lookups using the LDAP protocol. This is described
/*	in \fBldap_table\fR(5).
/* .IP "\fBmysql\fR (read-only)"
/*	Perform lookups using the MYSQL protocol. This is described
/*	in \fBmysql_table\fR(5).
/* .IP "\fBpcre\fR (read-only)"
/*	A lookup table based on Perl Compatible Regular Expressions. The
/*	file format is described in \fBpcre_table\fR(5).
/* .IP "\fBpgsql\fR (read-only)"
/*	Perform lookups using the PostgreSQL protocol. This is described
/*	in \fBpgsql_table\fR(5).
/* .IP "\fBproxy\fR (read-only)"
/*	A lookup table that is implemented via the Postfix
/*	\fBproxymap\fR(8) service. The table name syntax is
/*	\fItype\fB:\fIname\fR.
/* .IP "\fBregexp\fR (read-only)"
/*	A lookup table based on regular expressions. The file format is
/*	described in \fBregexp_table\fR(5).
/* .IP \fBsdbm\fR
/*	An indexed file type based on hashing.
/*	This is available only on systems with support for SDBM databases.
/* .IP "\fBstatic\fR (read-only)"
/*	A table that always returns its name as lookup result. For example,
/*	\fBstatic:foobar\fR always returns the string \fBfoobar\fR as lookup
/*	result.
/* .IP "\fBtcp\fR (read-only)"
/*	Perform lookups using a simple request-reply protocol that is
/*	described in tcp_table(5).
/*	This feature is not included with Postfix 2.1.
/* .IP "\fBunix\fR (read-only)"
/*	A limited way to query the UNIX authentication database. The
/*	following tables are implemented:
/* .RS
/*. IP \fBunix:passwd.byname\fR
/*	The table is the UNIX password database. The key is a login name.
/*	The result is a password file entry in passwd(5) format.
/* .IP \fBunix:group.byname\fR
/*	The table is the UNIX group database. The key is a group name.
/*	The result is a group file entry in group(5) format.
/* .RE
/* .RE
/* .sp
/*	Other table types may exist depending on how Postfix was built.
/* .IP \fB-n\fR
/*	Print parameter settings that are not left at their built-in
/*	default value, because they are explicitly specified in main.cf.
/* .IP \fB-v\fR
/*	Enable verbose logging for debugging purposes. Multiple \fB-v\fR
/*	options make the software increasingly verbose.
/* DIAGNOSTICS
/*	Problems are reported to the standard error stream.
/* ENVIRONMENT
/* .ad
/* .fi
/* .IP \fBMAIL_CONFIG\fR
/*	Directory with Postfix configuration files.
/* CONFIGURATION PARAMETERS
/* .ad
/* .fi
/*	The following \fBmain.cf\fR parameters are especially relevant to
/*	this program.
/*
/*	The text below provides only a parameter summary. See
/*	postconf(5) for more details including examples.
/* .IP "\fBconfig_directory (see 'postconf -d' output)\fR"
/*	The default location of the Postfix main.cf and master.cf
/*	configuration files.
/* FILES
/*	/etc/postfix/main.cf, Postfix configuration parameters
/* SEE ALSO
/*	postconf(5), configuration parameters
/* README FILES
/* .ad
/* .fi
/*	Use "\fBpostconf readme_directory\fR" or
/*	"\fBpostconf html_directory\fR" to locate this information.
/* .na
/* .nf
/*	DATABASE_README, Postfix lookup table overview
/* LICENSE
/* .ad
/* .fi
/*	The Secure Mailer license must be distributed with this software.
/* AUTHOR(S)
/*	Wietse Venema
/*	IBM T.J. Watson Research
/*	P.O. Box 704
/*	Yorktown Heights, NY 10598, USA
/*--*/

/* System library. */

#include <sys_defs.h>
#include <sys/stat.h>
#include <stdio.h>			/* rename() */
#include <pwd.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#ifdef STRCASECMP_IN_STRINGS_H
#include <strings.h>
#endif

#ifdef USE_PATHS_H
#include <paths.h>
#endif

/* Utility library. */

#include <msg.h>
#include <vstream.h>
#include <msg_vstream.h>
#include <get_hostname.h>
#include <stringops.h>
#include <htable.h>
#include <dict.h>
#include <safe.h>
#include <mymalloc.h>
#include <argv.h>
#include <split_at.h>
#include <vstring_vstream.h>
#include <myflock.h>

/* Global library. */

#include <mynetworks.h>
#include <mail_conf.h>
#include <mail_dict.h>
#include <mail_proto.h>
#include <mail_version.h>
#include <mail_params.h>
#include <mail_addr.h>
#include <mbox_conf.h>

 /*
  * What we're supposed to be doing.
  */
#define SHOW_NONDEF	(1<<0)		/* show non-default settings */
#define SHOW_DEFS	(1<<1)		/* show default setting */
#define SHOW_NAME	(1<<2)		/* show parameter name */
#define SHOW_MAPS	(1<<3)		/* show map types */
#define EDIT_MAIN	(1<<4)		/* edit main.cf */
#define SHOW_LOCKS	(1<<5)		/* show mailbox lock methods */
#define SHOW_EVAL	(1<<6)		/* expand right-hand sides */

 /*
  * Lookup table for in-core parameter info.
  */
HTABLE *param_table;

 /*
  * Lookup table for external parameter info.
  */
DICT   *text_table;

 /*
  * Declarations generated by scanning actual C source files.
  */
#include "time_vars.h"
#include "bool_vars.h"
#include "int_vars.h"
#include "str_vars.h"
#include "raw_vars.h"

 /*
  * Manually extracted.
  */
#include "auto_vars.h"
#include "install_vars.h"

 /*
  * Lookup tables generated by scanning actual C source files.
  */
static CONFIG_TIME_TABLE time_table[] = {
#include "time_table.h"
    0,
};

static CONFIG_BOOL_TABLE bool_table[] = {
#include "bool_table.h"
    0,
};

static CONFIG_INT_TABLE int_table[] = {
#include "int_table.h"
    0,
};

static CONFIG_STR_TABLE str_table[] = {
#include "str_table.h"
#include "auto_table.h"			/* XXX */
#include "install_table.h"
    0,
};

static CONFIG_RAW_TABLE raw_table[] = {
#include "raw_table.h"
    0,
};

 /*
  * Parameters with default values obtained via function calls.
  */
char   *var_myhostname;
char   *var_mydomain;
char   *var_mynetworks;

static const char *check_myhostname(void);
static const char *check_mydomainname(void);
static const char *check_mynetworks(void);

static CONFIG_STR_FN_TABLE str_fn_table[] = {
    VAR_MYHOSTNAME, check_myhostname, &var_myhostname, 1, 0,
    VAR_MYDOMAIN, check_mydomainname, &var_mydomain, 1, 0,
    0,
};
static CONFIG_STR_FN_TABLE str_fn_table_2[] = {
    VAR_MYNETWORKS, check_mynetworks, &var_mynetworks, 1, 0,
    0,
};

 /*
  * XXX Global so that call-backs can see it.
  */
static int mode = SHOW_NAME;

/* check_myhostname - lookup hostname and validate */

static const char *check_myhostname(void)
{
    static const char *name;
    const char *dot;
    const char *domain;

    /*
     * Use cached result.
     */
    if (name)
	return (name);

    /*
     * If the local machine name is not in FQDN form, try to append the
     * contents of $mydomain.
     * 
     * XXX Do not complain when running as "postconf -d".
     */
    name = get_hostname();
    if ((mode & SHOW_DEFS) == 0 && (dot = strchr(name, '.')) == 0) {
	if ((domain = mail_conf_lookup_eval(VAR_MYDOMAIN)) == 0) {
	    msg_warn("My hostname %s is not a fully qualified name - set %s or %s in %s/main.cf",
		     name, VAR_MYHOSTNAME, VAR_MYDOMAIN, var_config_dir);
	} else {
	    name = concatenate(name, ".", domain, (char *) 0);
	}
    }
    return (name);
}

/* get_myhostname - look up and store my hostname */

static void get_myhostname(void)
{
    const char *name;

    if ((name = mail_conf_lookup_eval(VAR_MYHOSTNAME)) == 0)
	name = check_myhostname();
    var_myhostname = mystrdup(name);
}

/* check_mydomainname - lookup domain name and validate */

static const char *check_mydomainname(void)
{
    char   *dot;

    /*
     * Use the hostname when it is not a FQDN ("foo"), or when the hostname
     * actually is a domain name ("foo.com").
     */
    if (var_myhostname == 0)
	get_myhostname();
    if ((dot = strchr(var_myhostname, '.')) == 0 || strchr(dot + 1, '.') == 0)
	return (var_myhostname);
    return (dot + 1);
}

/* check_mynetworks - lookup network address list */

static const char *check_mynetworks(void)
{
    const char *junk;

    if (var_inet_interfaces == 0) {
	if ((mode & SHOW_DEFS)
	    || !(junk = mail_conf_lookup_eval(VAR_INET_INTERFACES)))
	    junk = DEF_INET_INTERFACES;
	var_inet_interfaces = mystrdup(junk);
    }
    if (var_mynetworks_style == 0) {
	if ((mode & SHOW_DEFS)
	    || !(junk = mail_conf_lookup_eval(VAR_MYNETWORKS_STYLE)))
	    junk = DEF_MYNETWORKS_STYLE;
	var_mynetworks_style = mystrdup(junk);
    }
    return (mynetworks());
}

/* edit_parameters - edit parameter file */

static void edit_parameters(int argc, char **argv)
{
    char   *config_dir;
    char   *path;
    char   *temp;
    VSTREAM *src;
    VSTREAM *dst;
    VSTRING *buf = vstring_alloc(100);
    VSTRING *key = vstring_alloc(10);
    char   *cp;
    char   *edit_key;
    char   *edit_val;
    HTABLE *table;
    struct cvalue {
	char   *value;
	int     found;
    };
    struct cvalue *cvalue;
    HTABLE_INFO **ht_info;
    HTABLE_INFO **ht;
    int     interesting;
    const char *err;

    /*
     * Store command-line parameters for quick lookup.
     */
    table = htable_create(argc);
    while ((cp = *argv++) != 0) {
	if (strchr(cp, '\n') != 0)
	    msg_fatal("edit accepts no multi-line input");
	while (ISSPACE(*cp))
	    cp++;
	if (*cp == '#')
	    msg_fatal("edit accepts no comment input");
	if ((err = split_nameval(cp, &edit_key, &edit_val)) != 0)
	    msg_fatal("%s: \"%s\"", err, cp);
	cvalue = (struct cvalue *) mymalloc(sizeof(*cvalue));
	cvalue->value = edit_val;
	cvalue->found = 0;
	htable_enter(table, edit_key, (char *) cvalue);
    }

    /*
     * XXX Avoid code duplication by better code decomposition.
     */
    if (var_config_dir)
	myfree(var_config_dir);
    var_config_dir = mystrdup((config_dir = safe_getenv(CONF_ENV_PATH)) != 0 ?
			      config_dir : DEF_CONFIG_DIR);	/* XXX */
    set_mail_conf_str(VAR_CONFIG_DIR, var_config_dir);

    /*
     * Open the original file for input.
     */
    path = concatenate(var_config_dir, "/", "main.cf", (char *) 0);
    if ((src = vstream_fopen(path, O_RDONLY, 0)) == 0)
	msg_fatal("open %s for reading: %m", path);

    /*
     * Open a temp file for the result. We use a fixed name so we don't leave
     * behind thrash with random names. Lock the temp file to avoid
     * accidents. Truncate the file only after we have an exclusive lock.
     */
    temp = concatenate(path, ".tmp", (char *) 0);
    if ((dst = vstream_fopen(temp, O_CREAT | O_WRONLY, 0644)) == 0)
	msg_fatal("open %s: %m", temp);
    if (myflock(vstream_fileno(dst), INTERNAL_LOCK, MYFLOCK_OP_EXCLUSIVE) < 0)
	msg_fatal("lock %s: %m", temp);
    if (ftruncate(vstream_fileno(dst), 0) < 0)
	msg_fatal("truncate %s: %m", temp);

    /*
     * Copy original file to temp file, while replacing parameters on the
     * fly. Issue warnings for names found multiple times.
     */
#define STR(x) vstring_str(x)

    interesting = 0;
    while (vstring_get(buf, src) != VSTREAM_EOF) {
	for (cp = STR(buf); ISSPACE(*cp) /* including newline */ ; cp++)
	     /* void */ ;
	/* Copy comment, all-whitespace, or empty line. */
	if (*cp == '#' || *cp == 0) {
	    vstream_fputs(STR(buf), dst);
	}
	/* Copy or skip continued text. */
	else if (cp > STR(buf)) {
	    if (interesting == 0)
		vstream_fputs(STR(buf), dst);
	}
	/* Copy or replace start of logical line. */
	else {
	    vstring_strncpy(key, cp, strcspn(cp, " \t\r\n="));
	    cvalue = (struct cvalue *) htable_find(table, STR(key));
	    if ((interesting = !!cvalue) != 0) {
		if (cvalue->found++ == 1)
		    msg_warn("%s: multiple entries for \"%s\"", path, STR(key));
		vstream_fprintf(dst, "%s = %s\n", STR(key), cvalue->value);
	    } else {
		vstream_fputs(STR(buf), dst);
	    }
	}
    }

    /*
     * Generate new entries for parameters that were not found.
     */
    for (ht_info = ht = htable_list(table); *ht; ht++) {
	cvalue = (struct cvalue *) ht[0]->value;
	if (cvalue->found == 0)
	    vstream_fprintf(dst, "%s = %s\n", ht[0]->key, cvalue->value);
    }
    myfree((char *) ht_info);

    /*
     * When all is well, rename the temp file to the original one.
     */
    if (vstream_fclose(src))
	msg_fatal("read %s: %m", path);
    if (vstream_fclose(dst))
	msg_fatal("write %s: %m", temp);
    if (rename(temp, path) < 0)
	msg_fatal("rename %s to %s: %m", temp, path);

    /*
     * Cleanup.
     */
    myfree(path);
    myfree(temp);
    vstring_free(buf);
    vstring_free(key);
    htable_free(table, myfree);
}

/* read_parameters - read parameter info from file */

static void read_parameters(void)
{
    char   *config_dir;
    char   *path;

    /*
     * A direct rip-off of mail_conf_read(). XXX Avoid code duplication by
     * better code decomposition.
     */
    dict_unknown_allowed = 1;
    if (var_config_dir)
	myfree(var_config_dir);
    var_config_dir = mystrdup((config_dir = safe_getenv(CONF_ENV_PATH)) != 0 ?
			      config_dir : DEF_CONFIG_DIR);	/* XXX */
    set_mail_conf_str(VAR_CONFIG_DIR, var_config_dir);
    path = concatenate(var_config_dir, "/", "main.cf", (char *) 0);
    dict_load_file(CONFIG_DICT, path);
    myfree(path);
}

/* set_parameters - set parameter values from default or explicit setting */

static void set_parameters(void)
{

    /*
     * Populate the configuration parameter dictionary with default settings
     * or with actual settings.
     * 
     * Iterate over each entry in str_fn_table, str_fn_table_2, time_table,
     * bool_table, int_table, str_table, and raw_table. Look up each
     * parameter name in the configuration parameter dictionary. If the
     * parameter is not set, take the default value, or take the value from
     * main.cf, without doing $name expansions. This includes converting
     * default values from numeric/boolean internal forms to external string
     * form.
     * 
     * Once the configuration parameter dictionary is populated, printing a
     * parameter setting is a matter of querying the configuration parameter
     * dictionary, optionally expanding of $name values, and printing the
     * result.
     */
}

/* hash_parameters - hash all parameter names so we can find and sort them */

static void hash_parameters(void)
{
    CONFIG_TIME_TABLE *ctt;
    CONFIG_BOOL_TABLE *cbt;
    CONFIG_INT_TABLE *cit;
    CONFIG_STR_TABLE *cst;
    CONFIG_STR_FN_TABLE *csft;
    CONFIG_RAW_TABLE *rst;

    param_table = htable_create(100);

    for (ctt = time_table; ctt->name; ctt++)
	htable_enter(param_table, ctt->name, (char *) ctt);
    for (cbt = bool_table; cbt->name; cbt++)
	htable_enter(param_table, cbt->name, (char *) cbt);
    for (cit = int_table; cit->name; cit++)
	htable_enter(param_table, cit->name, (char *) cit);
    for (cst = str_table; cst->name; cst++)
	htable_enter(param_table, cst->name, (char *) cst);
    for (csft = str_fn_table; csft->name; csft++)
	htable_enter(param_table, csft->name, (char *) csft);
    for (csft = str_fn_table_2; csft->name; csft++)
	htable_enter(param_table, csft->name, (char *) csft);
    for (rst = raw_table; rst->name; rst++)
	htable_enter(param_table, rst->name, (char *) rst);
}

/* show_strval - show string-valued parameter */

static void show_strval(int mode, const char *name, const char *value)
{
    if (mode & SHOW_EVAL)
	value = mail_conf_eval(value);

    if (mode & SHOW_NAME) {
	vstream_printf("%s = %s\n", name, value);
    } else {
	vstream_printf("%s\n", value);
    }
}

/* show_intval - show integer-valued parameter */

static void show_intval(int mode, const char *name, int value)
{
    if (mode & SHOW_NAME) {
	vstream_printf("%s = %d\n", name, value);
    } else {
	vstream_printf("%d\n", value);
    }
}

/* print_bool - print boolean parameter */

static void print_bool(int mode, CONFIG_BOOL_TABLE *cbt)
{
    const char *value;

    if (mode & SHOW_DEFS) {
	show_strval(mode, cbt->name, cbt->defval ? "yes" : "no");
    } else {
	value = dict_lookup(CONFIG_DICT, cbt->name);
	if ((mode & SHOW_NONDEF) == 0) {
	    if (value == 0) {
		show_strval(mode, cbt->name, cbt->defval ? "yes" : "no");
	    } else {
		show_strval(mode, cbt->name, value);
	    }
	} else {
	    if (value != 0)
		show_strval(mode, cbt->name, value);
	}
    }
}

/* print_time - print relative time parameter */

static void print_time(int mode, CONFIG_TIME_TABLE *ctt)
{
    const char *value;

    if (mode & SHOW_DEFS) {
	show_strval(mode, ctt->name, ctt->defval);
    } else {
	value = dict_lookup(CONFIG_DICT, ctt->name);
	if ((mode & SHOW_NONDEF) == 0) {
	    if (value == 0) {
		show_strval(mode, ctt->name, ctt->defval);
	    } else {
		show_strval(mode, ctt->name, value);
	    }
	} else {
	    if (value != 0)
		show_strval(mode, ctt->name, value);
	}
    }
}

/* print_int - print integer parameter */

static void print_int(int mode, CONFIG_INT_TABLE *cit)
{
    const char *value;

    if (mode & SHOW_DEFS) {
	show_intval(mode, cit->name, cit->defval);
    } else {
	value = dict_lookup(CONFIG_DICT, cit->name);
	if ((mode & SHOW_NONDEF) == 0) {
	    if (value == 0) {
		show_intval(mode, cit->name, cit->defval);
	    } else {
		show_strval(mode, cit->name, value);
	    }
	} else {
	    if (value != 0)
		show_strval(mode, cit->name, value);
	}
    }
}

/* print_str - print string parameter */

static void print_str(int mode, CONFIG_STR_TABLE *cst)
{
    const char *value;

    if (mode & SHOW_DEFS) {
	show_strval(mode, cst->name, cst->defval);
    } else {
	value = dict_lookup(CONFIG_DICT, cst->name);
	if ((mode & SHOW_NONDEF) == 0) {
	    if (value == 0) {
		show_strval(mode, cst->name, cst->defval);
	    } else {
		show_strval(mode, cst->name, value);
	    }
	} else {
	    if (value != 0)
		show_strval(mode, cst->name, value);
	}
    }
}

/* print_str_fn - print string-function parameter */

static void print_str_fn(int mode, CONFIG_STR_FN_TABLE *csft)
{
    const char *value;

    if (mode & SHOW_DEFS) {
	show_strval(mode, csft->name, csft->defval());
    } else {
	value = dict_lookup(CONFIG_DICT, csft->name);
	if ((mode & SHOW_NONDEF) == 0) {
	    if (value == 0) {
		show_strval(mode, csft->name, csft->defval());
	    } else {
		show_strval(mode, csft->name, value);
	    }
	} else {
	    if (value != 0)
		show_strval(mode, csft->name, value);
	}
    }
}

/* print_str_fn_2 - print string-function parameter */

static void print_str_fn_2(int mode, CONFIG_STR_FN_TABLE *csft)
{
    const char *value;

    if (mode & SHOW_DEFS) {
	show_strval(mode, csft->name, csft->defval());
    } else {
	value = dict_lookup(CONFIG_DICT, csft->name);
	if ((mode & SHOW_NONDEF) == 0) {
	    if (value == 0) {
		show_strval(mode, csft->name, csft->defval());
	    } else {
		show_strval(mode, csft->name, value);
	    }
	} else {
	    if (value != 0)
		show_strval(mode, csft->name, value);
	}
    }
}

/* print_raw - print raw string parameter */

static void print_raw(int mode, CONFIG_RAW_TABLE * rst)
{
    const char *value;

    if (mode & SHOW_EVAL)
	msg_warn("parameter %s expands at run-time", rst->name);
    mode &= ~SHOW_EVAL;

    if (mode & SHOW_DEFS) {
	show_strval(mode, rst->name, rst->defval);
    } else {
	value = dict_lookup(CONFIG_DICT, rst->name);
	if ((mode & SHOW_NONDEF) == 0) {
	    if (value == 0) {
		show_strval(mode, rst->name, rst->defval);
	    } else {
		show_strval(mode, rst->name, value);
	    }
	} else {
	    if (value != 0)
		show_strval(mode, rst->name, value);
	}
    }
}

/* print_parameter - show specific parameter */

static void print_parameter(int mode, char *ptr)
{

#define INSIDE(p,t) (ptr >= (char *) t && ptr < ((char *) t) + sizeof(t))

    /*
     * This is gross, but the best we can do on short notice.
     */
    if (INSIDE(ptr, time_table))
	print_time(mode, (CONFIG_TIME_TABLE *) ptr);
    if (INSIDE(ptr, bool_table))
	print_bool(mode, (CONFIG_BOOL_TABLE *) ptr);
    if (INSIDE(ptr, int_table))
	print_int(mode, (CONFIG_INT_TABLE *) ptr);
    if (INSIDE(ptr, str_table))
	print_str(mode, (CONFIG_STR_TABLE *) ptr);
    if (INSIDE(ptr, str_fn_table))
	print_str_fn(mode, (CONFIG_STR_FN_TABLE *) ptr);
    if (INSIDE(ptr, str_fn_table_2))
	print_str_fn_2(mode, (CONFIG_STR_FN_TABLE *) ptr);
    if (INSIDE(ptr, raw_table))
	print_raw(mode, (CONFIG_RAW_TABLE *) ptr);
    if (msg_verbose)
	vstream_fflush(VSTREAM_OUT);
}

/* comp_names - qsort helper */

static int comp_names(const void *a, const void *b)
{
    HTABLE_INFO **ap = (HTABLE_INFO **) a;
    HTABLE_INFO **bp = (HTABLE_INFO **) b;

    return (strcmp(ap[0]->key, bp[0]->key));
}

/* show_maps - show available maps */

static void show_maps(void)
{
    ARGV   *maps_argv;
    int     i;

    maps_argv = dict_mapnames();
    for (i = 0; i < maps_argv->argc; i++)
	vstream_printf("%s\n", maps_argv->argv[i]);
    argv_free(maps_argv);
}

/* show_locks - show available mailbox locking methods */

static void show_locks(void)
{
    ARGV   *maps_argv;
    int     i;

    maps_argv = mbox_lock_names();
    for (i = 0; i < maps_argv->argc; i++)
	vstream_printf("%s\n", maps_argv->argv[i]);
    argv_free(maps_argv);
}

/* show_parameters - show parameter info */

static void show_parameters(int mode, char **names)
{
    HTABLE_INFO **list;
    HTABLE_INFO **ht;
    char  **namep;
    char   *value;

    /*
     * Show all parameters.
     */
    if (*names == 0) {
	list = htable_list(param_table);
	qsort((char *) list, param_table->used, sizeof(*list), comp_names);
	for (ht = list; *ht; ht++)
	    print_parameter(mode, ht[0]->value);
	myfree((char *) list);
	return;
    }

    /*
     * Show named parameters.
     */
    for (namep = names; *namep; namep++) {
	if ((value = htable_find(param_table, *namep)) == 0) {
	    msg_warn("%s: unknown parameter", *namep);
	} else {
	    print_parameter(mode, value);
	}
    }
}

/* main */

int     main(int argc, char **argv)
{
    int     ch;
    int     fd;
    struct stat st;
    int     junk;

    /*
     * Be consistent with file permissions.
     */
    umask(022);

    /*
     * To minimize confusion, make sure that the standard file descriptors
     * are open before opening anything else. XXX Work around for 44BSD where
     * fstat can return EBADF on an open file descriptor.
     */
    for (fd = 0; fd < 3; fd++)
	if (fstat(fd, &st) == -1
	    && (close(fd), open("/dev/null", O_RDWR, 0)) != fd)
	    msg_fatal("open /dev/null: %m");

    /*
     * Set up logging.
     */
    msg_vstream_init(argv[0], VSTREAM_ERR);

    /*
     * Parse JCL.
     */
    while ((ch = GETOPT(argc, argv, "c:deEhmlnv")) > 0) {
	switch (ch) {
	case 'c':
	    if (setenv(CONF_ENV_PATH, optarg, 1) < 0)
		msg_fatal("out of memory");
	    break;
	case 'd':
	    mode |= SHOW_DEFS;
	    break;
	case 'e':
	    mode |= EDIT_MAIN;
	    break;

	    /*
	     * People, this does not work unless you properly handle default
	     * settings. For example, fast_flush_domains = $relay_domains
	     * must not evaluate to the empty string when relay_domains is
	     * left at its default setting of $mydestination.
	     */
#if 0
	case 'E':
	    mode |= SHOW_EVAL;
	    break;
#endif
	case 'h':
	    mode &= ~SHOW_NAME;
	    break;
	case 'l':
	    mode |= SHOW_LOCKS;
	    break;
	case 'm':
	    mode |= SHOW_MAPS;
	    break;
	case 'n':
	    mode |= SHOW_NONDEF;
	    break;
	case 'v':
	    msg_verbose++;
	    break;
	default:
	    msg_fatal("usage: %s [-c config_dir] [-d (defaults)] [-e (edit)] [-h (no names)] [-l (lock types)] [-m (map types)] [-n (non-defaults)] [-v] [name...]", argv[0]);
	}
    }

    /*
     * Sanity check.
     */
    junk = (mode & (SHOW_DEFS | SHOW_NONDEF | SHOW_MAPS | SHOW_LOCKS | EDIT_MAIN));
    if (junk != 0 && junk != SHOW_DEFS && junk != SHOW_NONDEF
	&& junk != SHOW_MAPS && junk != SHOW_LOCKS && junk != EDIT_MAIN)
	msg_fatal("specify one of -d, -e, -m, -l and -n");

    /*
     * If showing map types, show them and exit
     */
    if (mode & SHOW_MAPS) {
	mail_dict_init();
	show_maps();
    }

    /*
     * If showing locking methods, show them and exit
     */
    else if (mode & SHOW_LOCKS) {
	show_locks();
    }

    /*
     * Edit main.cf.
     */
    else if (mode & EDIT_MAIN) {
	edit_parameters(argc - optind, argv + optind);
    }

    /*
     * If showing non-default values, read main.cf.
     */
    else {
	if ((mode & SHOW_DEFS) == 0) {
	    read_parameters();
	    set_parameters();
	}

	/*
	 * Throw together all parameters and show the asked values.
	 */
	hash_parameters();
	show_parameters(mode, argv + optind);
    }
    vstream_fflush(VSTREAM_OUT);
    exit(0);
}
