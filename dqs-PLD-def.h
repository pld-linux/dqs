static char def_rcsid[]="$Id$";

/*----------------------------------------------------
 * def.h Tom Green Mon Jan 31 10:44:27 1994
 *
 * Copyright 1993
 *
 * SUPER COMPUTER COMPUTATIONS RESEARCH INSTITUTE
 *            FLORIDA STATE UNIVERSITY
 *
 *
 * SCRI representatives make no claims about the
 * suitability of this software for any purpose.
 * It is provided "as is" without express or
 * implied warranty.
 *
 * $Log$
 * Revision 1.8  2000/03/09 03:56:07  chuck
 * Modified FLOCK macro for lockf on System 5 hosts and flock on
 * BSD hosts.  FLOCK now only locks.  New macro FUNLOCK is now used
 * to unlock.
 *
 * Revision 1.7  2000/03/09 03:51:22  chuck
 * Fixed a memory leak in the UNPACKSTR macro.
 * An input argument was overwritten without first releasing
 * the memory it pointed to.
 *
 * Revision 1.6  1999/04/30 16:46:26  green
 * reworked file locking in dqs_log.c to use MACRO FLOCK defined in def.h
 * so that AIX doesn't have to include -lbsd
 *
 * Revision 1.5  1999/04/30 14:50:52  green
 * support for changing from hex to base10 for queue configurations
 *
 * Revision 1.4  1998/10/26 19:24:09  green
 * use the DQS_EXIT macro to determine exit value of ancillaries
 *
 * Revision 1.3  1998/10/21 14:42:52  green
 * Red Hat Alpha Port - ADDRLEN incorporated
 *                      SETPGRP/GETPGRP macros redefined
 *
 * Revision 1.2  1998/10/13 15:08:48  green
 * Solaris 2.6 support - hopefully, as I don't have access to one...
 *
 * Revision 1.1.1.1  1998/08/18 14:39:10  green
 * DQS 3.2.0.5 WIP Import
 *
 * Revision 1.5  1997/10/21 15:51:19  decker
 * Expanded MAX_STRING_SIZE and TOKEN_SIZE to 2048
 *
 * Revision 1.4  1997/09/04 16:39:05  decker
 * Ron Lee's Patch for VALID,SETBIT,CLEARBIT added
 *
 * Revision 1.3  1997/08/08 15:17:14  decker
 * Added David Geldreich Patch:
 *
 * Revision 1.2  1997/04/10 21:51:49  green
 * added def for rindex
 *
 * Revision 1.1.1.1  1997/04/10 15:10:31  green
 * DQS 3.1.3.4.1 Distribution
 *
 * Revision 3.60  1996/08/26 14:20:45  nrl
 * Incorporated SCRI scheduling changes
 *
 * Revision 3.59  1996/08/16  17:44:42  nrl
 * Added SETEUID macro to def.h to provide differentiation
 * for HP from the rest of the pack.
 *
 * Revision 3.58  1996/07/09  19:53:12  nrl
 * Added SOLARIS2.5 parameters
 *
 * Revision 3.57  1996/06/27  01:55:37  nrl
 * changes to accomodate osf gcc
 *
 * Revision 3.55  1996/06/26  19:08:44  nrl
 * set JOBS_SCANNED_PER_PASS to very large number to force
 * a relook at the entire queue each time.
 *
 * Revision 3.54  1996/06/26  14:03:19  nrl
 * Added pvmcleanup.sh to install.. added osf2.3 detection
 *
 * Revision 3.53  1996/06/17  02:28:36  nrl
 * Updtaes from Guntram Wolski, Ron Lee, John Makosky and
 * Bodo Beckebach
 *
 * Revision 3.52  1996/04/01  21:35:38  nrl
 * removed absolte path from DEBUG313,txt file name
 *
 * Revision 3.51  1996/03/25  16:28:26  nrl
 * Repaired parameter scanning for qidle
 *
 * Revision 3.50  1996/03/21  17:06:37  nrl
 * added fortran and "c" syntax to resource requests
 *
 * Revision 3.49  1996/03/19  23:27:01  nrl
 * added capability to clean up consumable resources whenthey
 * get out of sync with reality
 *
 * Revision 3.48  1996/03/17  00:57:28  nrl
 * merge in qsub prevalidation scheme and consumable restoration
 *
 * Revision 3.47  1996/03/14  03:15:57  nrl
 * merge in subordinate queues and consumable resource changes
 *
 * Revision 3.46  1996/03/12  17:11:45  nrl
 * removed aborts and replaced with an error messaging scheme
 * to send email to the dqs adminsitrator and wait for
 * actions by that administrator
 *
 * Revision 3.45  1996/02/07  13:07:37  nrl
 * Added "process leader" and TMP_FILES link capability
 *
 * Revision 3.44  1996/01/19  20:58:36  nrl
 * merged SCRI code and new job and queue structure changes
 *
 * Revision 3.43  1995/10/23  18:51:37  nrl
 * Added fix for setpgrp (once more) for Solaris 2.4, recommended by
 * Ron Lee
 *
 * Revision 3.42  1995/07/13  20:51:06  nrl
 * This is the contribution of that almost anonymous fellow
 * Ron lee from a company which does not its name mentioned..
 * which finally!! (we hope) solves ALL the Solaris 2.4 problems.
 *
 * Revision 3.41  1995/07/12  18:47:48  nrl
 * Fixed numerous problmes with Irix 5.3 and 6.0 systems
 *
 * Revision 3.40  1995/06/22  19:31:07  nrl
 * Added kludgie "subpriority" field to differentiate jobs from the
 * same user. Also fixed MAXUJOBS and added "MAXU" warning to
 * the "qstat" command.
 *
 * Revision 3.39  1995/06/21  16:57:28  nrl
 * Major scheduling changes... added a subpriority field to manage
 * things within the user submitted priority. Added priority info to the
 * accounting file.
 *
 * Revision 3.38  1995/06/15  17:20:51  nrl
 * Mike Iglesias solved the setpriority problem on OSF platforms
 *
 * Revision 3.37  1995/06/15  14:20:54  nrl
 * changed SETPGRP for OSF systems to use setpgid
 *
 * Revision 3.36  1995/06/13  12:06:11  nrl
 * Updated count of variables for fscanf testing
 *
 * Revision 3.35  1995/05/29  18:08:44  nrl
 * More solaris stuff GAGGHH had to differentiate more cases of
 * solaris2.3 and solaris2.4 stuff
 *
 * Revision 3.34  1995/05/28  16:44:35  nrl
 * Fixes for solaris2.3 and solaris 2.4 and mailer default recipients
 *
 * Revision 3.33  1995/05/14  18:28:46  nrl
 * Plugged one hole in dqs_execd and qmaster handhsaking...
 * added gethostbyname calls to overcome problems with some
 * systems
 *
 * Revision 3.32  1995/03/05  03:46:56  nrl
 * Included Axel Brandes job scheduling mechanism to keep one
 * user from hawging the queue.
 *
 * Revision 3.31  1995/02/22  14:29:13  nrl
 * added "FREE" macro to make sure all freed pointers are NULL,
 * replaced all calls to free( ) with FREE.
 *
 * Revision 3.30  1995/02/20  01:02:59  nrl
 * corrected SUN changes for bcmp,bcopy and bzero
 *
 * Revision 3.29  1995/02/19  22:37:48  nrl
 * Simplified pvm and tcgmsg interface to a minimalist scheme requiring
 * user scripts to start the daemons
 *
 * Revision 3.28  1995/02/17  02:56:51  nrl
 * Added formal skeletons for PVM and TCGMSG parallel modes
 *
 * Revision 3.27  1995/02/09  12:48:57  nrl
 * Added "delete complex" and "modify complex"
 *
 * Revision 3.26  1995/02/06  16:31:48  nrl
 * Added "account" info to rusage structure and to the "acc_file"
 * for analysis by user.
 *
 * Revision 3.25  1995/01/17  16:31:57  nrl
 * completed mailer feature
 *
 * Revision 3.24  1994/11/14  13:56:36  green
 * fixed hpux "nice"
 * 536c536
 * < #define SETPRIORITY(niceval) nice(GETPGRP,niceval)
 * ---
 * > #define SETPRIORITY(niceval) nice(niceval)
 * --------------------------------------------------------------------
 *
 * Revision 3.23  1994/08/02  23:11:05  green
 * added support for a crude job staging mechanism
 *
 * Revision 3.22  1994/07/05  14:22:27  green
 * added James MacKinnon's NeXT ports
 *
 * Revision 3.21  1994/06/12  23:18:00  green
 * yanked NCARGS
 *
 * Revision 3.20  1994/06/12  21:04:56  green
 * expanded DQS_MAXNAMELEN to MAX_STRING_SIZE in def.h
 *
 * utilize DQS_MAXNAMELEN for command size in dqs_dshd.c
 *
 * Revision 3.19  1994/06/09  18:38:20  green
 * had some problems with nonre-entrant gethostbyX in dqs_sec.c - fixed
 *
 * #def overload for "GENERIC" in def.h - fixed
 *
 * Revision 3.18  1994/06/09  14:25:04  green
 * yanked PVM after further digging through the PVM code decided there
 * might be potential problems(let somebody else worry with pvm if they
 * want it...)
 *
 * pulled out some sloaris #defs - maybe one day SUN will ship me my
 * compiler
 *
 * Revision 3.17  1994/06/08  17:48:00  green
 * added P4 support(with the help of Ralph Butler - Thanks Ralph!)
 *
 * backed down to Rev. 3.3 of dqs_check_to_do_list.c
 *
 * Revision 3.16  1994/06/07  16:45:37  green
 * more "sloaris" porting...
 *
 * Revision 3.15  1994/06/07  12:37:55  green
 * moved some format descriptors out of dqs_ck_to_do_list.c and
 * dqs_job_exeit.c and into def.h
 *
 * added dqs_read_stats() to dqs_ck_to_do_list.c
 *
 * Revision 3.14  1994/06/06  01:23:01  green
 * added "dqs_dshd_service" to the DQS config
 *
 * add "-par pvm" - though we do NOT intend to support it
 * (see dqs_start_pvm.c for a more thorough discussion)
 *
 * Revision 3.13  1994/06/04  15:24:28  green
 * added "-par parallel_packge" support
 *
 * Revision 3.12  1994/06/04  14:49:41  green
 * added necessary P4/MPI defs
 *
 * Revision 3.11  1994/06/02  13:44:26  green
 * attempt to port to Sloaris...
 * Work In Progress(WIPed)
 *
 * Revision 3.10  1994/05/31  12:23:32  green
 * modified #define for GETPGRP such that __osf__ doesn't utilize args
 *
 * Revision 3.9  1994/05/31  12:03:45  green
 * some OSes define MAXNAMELEN - some don't
 * handled with an ifndef in def.h
 *
 * removed "#include "h.h"" in defined.c
 *
 * yanked ANSI prototyping in dsh.c/dshd.c as some(sic) C compilers can't
 * swallow them
 *
 * #ifdef'ed fcntl(F_SETOWN) out for HPUX in dsh.c as HPUX doesn't define
 * it
 *
 * #ifdef'ed "#include <sys/select.h>" out of h.h #ifdefed
 * __hpux/bsd_4_2/SVR3/__osf__.(taken care of in types.h in most of
 * these.)
 *
 * Revision 3.8  1994/05/31  10:30:36  green
 * some OSes define NCARGS, some don't - handle with ifndef...
 *
 * Revision 3.7  1994/05/31  00:52:40  green
 * added dsh.c dshd.c to Makefile.proto
 *
 * added MAXNAMELEN and NCARGS to def.h
 *
 * type casting in dqs_reauth.c, dqs_sec.c, dqs_setup.c to hush gcc
 * warnings
 *
 * added jmp_buf to globals.h, changed Revision number in globals.h
 *
 * added dsh and dshd tp prognames.h
 *
 * Revision 3.6  1994/05/30  23:56:16  green
 * added necessary defs for DCMD/DSH to def.h
 *
 * added notes on necessary hooks to dqs_execd.c reqd for direct execing
 * of dsh
 *
 * added "#include <setjmp.h>" to h.h
 *
 * Revision 3.5  1994/05/04  17:54:53  green
 * added FreeBSD support(Pedro A M Vazquez)
 *
 * Revision 3.4  1994/04/01  02:59:28  green
 * added "qalter" support
 *
 * Revision 3.3  1994/03/27  05:59:44  green
 * def.h:UNPACKSTR() modified to force a NULL as realloc() doesn't
 * necessarily return clean memory
 *
 * dqs_list.c:dqs_insert(TAIL) had a bug wheninserting to a NULL head
 *
 * may "Last Minute Hack" to dqs_list.c:dqs_showlist() really screwed up
 * some things - yanked...
 *
 * Revision 3.2  1994/03/26  16:33:33  green
 * added "-srl" support.
 *
 * dqs_resolve.c:dqs_read_resolve_file() now returns the primary qmaster
 * name for fields marked as "none"
 *
 * Revision 3.1  1994/03/26  15:29:14  green
 * allowed for "qconf -sq [dest_id_list]" vs "qconf -sq dest_id_list"
 *
 * write generic queue configuration in common_dir
 *
 * Revision 3.0  1994/03/07  04:13:02  green
 * 3.0 freeze
 *
 * Revision 1.8  1994/02/25  23:13:17  green
 * added "PID_FILE" to def.h to log process id.
 *
 * modified dqs_execd.c and qmaster.c to log pids to a file
 *
 * added dqs_log_pid() to dqs_utility.c
 *
 * remade func.h
 *
 * forced insertion of "green" into Man_head  -- this needs to be removed
 * and a def in dqs.h if running as non-root.
 *
 * Revision 1.7  1994/02/24  01:10:01  green
 * added default compile flags in Makefile.proto
 *
 * modified GETPGRP() and SETPGRP() in def.h for IRIX 5.1.1.1 support
 *
 * changed "st_mtime" to "st_m_time" in dqs_reauth.cand dqs_sec.c
 * for IRIX 5.1.1.1 support
 *
 * Revision 1.6  1994/02/23  16:19:16  green
 * added "QUSAGE" to def.h
 *
 * Revision 1.5  1994/02/17  14:48:57  green
 * added MAX_KLOG_TIME to def.h
 *
 * added some strategic dqs_set_coresize_2_0() as CYAs
 *
 * nuked some dqs_set_coresize_back_normal()
 *
 * dinked with ALRM handlers for "robustness"
 *
 * NOTE: HPUX does not support core limit size --- sad...
 *
 * Revision 1.4  1994/02/10  20:58:37  green
 * moved "LOG_FILE" and "ERR_FILE" out of def.h to dqs.h
 *
 * fixed "-Passwd passwd_file" option
 *
 * Revision 1.3  1994/02/09  19:47:58  green
 * syncing source with docs
 *
 * Revision 1.2  1994/02/02  20:22:05  green
 * cleaned up "qconf.c" to sync with docs
 *
 * Revision 1.1.1.1  1994/02/01  17:57:36  green
 * DQS 3.0 ALPHA
 *
 *--------------------------------------------------*/

/* logicals */

#ifndef FALSE
#define FALSE                0
#endif
#ifndef TRUE
#define TRUE                 1
#endif



/* DQS_COMPILE_DEBUG inserts debugging macros
 * LEAVE THEM IN!(or don't call if ya need help)
 */

#define DQS_COMPILE_DEBUG
#define DEBUG_FILE stderr

#define DEFAULT_EDITOR     "vi"
#define DQS_MAX_FD         600
#define MAX_SEQNUM         999999
#define MAX_PATH           2048

/*********************************************************/

#ifdef __alpha
#define u_long32 u_int
#else
#define u_long32 u_long
#endif

/*********************************************************/
/* Job states */
#define IDLE                                0

/* Batch Services Summary */

#define JOB_EXECUTION                       300
#define JOB_ROUTING                         301
#define JOB_EXIT                            302
#define BATCH_SERVER_RESTART                303
#define JOB_ABORTS                          304
#define QUEUE_JOB_REQUEST                   305
#define MODIFY_JOB_REQUEST                  306
#define DELETE_JOB_REQUEST                  307
#define JOB_MESSAGE_REQUEST                 308
#define RERUN_JOB_REQUEST                   309
#define SIGNAL_JOB_REQUEST                  310
#define JOB_STATUS_REQUEST                  311
#define QUEUE_STATUS_REQUEST                312
#define SERVER_STATUS_REQUEST               313
#define SELECT_JOBS_REQUEST                 314
#define MOVE_JOB_REQUEST                    315
#define HOLD_JOB_REQUEST                    316
#define RELEASE_JOB_REQUEST                 317
#define SERVER_SHUTDOWN_REQUEST             318
#define LOCATE_JOB_REQUEST                  319
#define SIGNAL_QUEUE_REQUEST                320

#define STARTING_UP                         321   /* NOT PART OF P1003.15D12! */
#define DQS_ACK                             500
#define DQS_NAK                             501
#define LOAD_AVG                            322

#define QMASTER_ACTION_REQUEST              323   /* sent to the qmaster for help  */
#define DQS_EXECD_ACTION_REQUEST            344   /* sent to the dqs_execd by the qmaster  */

/*       Action sub fields           */
#define SYNCHRONIZE                         001
#define ERROR_REPORT                        002
#define SLAVE_PROCESS_ALERT                 003
#define KILL_SLAVE_PROCESS                  004
#define REFRESH                             005
#define SHUTDOWN                            006
#define MAIL_TO_ADMINISTRATOR               007

/* return codes */
#define DENIED                              400
#define ACCEPTED                            401

/********************************************************************************/
/************    scheduling constants   *****************************************/

#define BASE_PRIORITY  1024
#define PRIORITY_OFFSET 8
#define NEWCOMER_FLAG     0x1000000
/* forced negative sign bit  */
#define MAX_JOBS_EXCEEDED 0x8000000
#define ALREADY_SCANNED   0x4000000

#define PRIORITY_MASK     0xffff00
#define SUBPRIORITY_MASK  0x0000ff

#define JOBS_SCANNED_PER_PASS 4000
/********************************************************************************/

/* Event logging controls */
#define LOG_VIA_SYSLOG                     500   /* log via syslogd */
#define LOG_VIA_FILE                       501   /* log via logfile */
#define LOG_VIA_COMBO                      502   /* log messages both ways */

#define LOG_EXTDEBUG                       LOG_DEBUG+1

/********************************************************************************/

/* misc */
#define ASCENDING                          600
#define DESCENDING                         601
#define HEAD                               602
#define TAIL                               603

/********************************************************************************/

/* Shell strategies */

#define DQS_FIXED_SHELL                    700
#define DQS_FLOATING_SHELL                 701

/********************************************************************************/

/* remap signals */

#define DQS_SIGHUP                         901
#define DQS_SIGINT                         902
#define DQS_SIGQUIT                        903
#define DQS_SIGILL                         904
#define DQS_SIGTRAP                        905
#define DQS_SIGABRT                        906
#define DQS_SIGIOT                         907
#define DQS_SIGEMT                         908
#define DQS_SIGFPE                         909
#define DQS_SIGKILL                        910
#define DQS_SIGBUS                         911
#define DQS_SIGSEGV                        912
#define DQS_SIGSYS                         913
#define DQS_SIGPIPE                        914
#define DQS_SIGALRM                        915
#define DQS_SIGTERM                        916
#define DQS_SIGURG                         917
#define DQS_SIGSTOP                        918
#define DQS_SIGTSTP                        919
#define DQS_SIGCONT                        920
#define DQS_SIGCHLD                        921
#define DQS_SIGTTIN                        922
#define DQS_SIGTTOU                        923
#define DQS_SIGIO                          924
#define DQS_SIGXCPU                        925
#define DQS_SIGXFSZ                        926
#define DQS_SIGVTALRM                      927
#define DQS_SIGPROF                        928
#define DQS_SIGWINCH                       929
#define DQS_SIGLOST                        930
#define DQS_SIGUSR1                        931
#define DQS_SIGUSR2                        932

/********************************************************************************/
/* Symbolic Constants */

/* misc */

#define NONE                               0x00000000
#define ALL                                0x77777777

/* Checkpoint/Restart Constants */
/* use dqs_show_checkpoint()    */

#define CHECKPOINT_AT_MINIMUM_INTERVAL_SYM 'm'
#define CHECKPOINT_AT_MINIMUM_INTERVAL     0x00000001
#define CHECKPOINT_AT_SHUTDOWN_SYM         's'
#define CHECKPOINT_AT_SHUTDOWN             0x00000002
#define CHECKPOINT_AT_UNSPECIFIED_SYM      'u'
#define CHECKPOINT_AT_UNSPECIFIED          0x00000004
#define NO_CHECKPOINT_SYM                  'n'
#define NO_CHECKPOINT                      0x00000008

/* Hold Type Constants */
#define NO_HOLD_SYM                        'n'
#define NO_HOLD                            0x000000010
#define OTHER_SYM                          'o'
#define OTHER                              0x000000020
#define SYSTEM_SYM                         's'
#define SYSTEM                             0x000000040
#define USER_SYM                           'u'
#define USER                               0x000000080

/* Job/Queue State Constants */
/* use dqs_show_states() */

#define ALARM_SYM                          'a'
#define ALARM                              0x000000001
#define SUSPEND_ON_COMP_SYM                'c'   /* NOT PART OF P1003.15D12! */
#define SUSPEND_ON_COMP                    0x000000002
#define DISABLED_SYM                       'd'
#define DISABLED                           0x000000004
#define ENABLED_SYM                        'e'
#define ENABLED                            0x000000008
#define HELD_SYM                           'h'
#define HELD                               0x000000010
#define MIGRATING_SYM                      'm'   /* NOT PART OF P1003.15D12! */
#define MIGRATING                          0x000000020
#define QUEUED_SYM                         'q'
#define QUEUED                             0x000000040
#define RUNNING_SYM                        'r'
#define RUNNING                            0x000000080
#define SUSPENDED_SYM                      's'   /* NOT PART OF P1003.15D12! */
#define SUSPENDED                          0x000000100
#define TRANSISTING_SYM                    't'
#define TRANSISTING                        0x000000200
#define UNKNOWN_SYM                        'u'
#define UNKNOWN                            0x000000400
#define WAITING_SYM                        'w'
#define WAITING                            0x000000800
#define EXITING_SYM                        'x'   /* NOT P1003.15D12 compliant! 'e' */
#define EXITING                            0x000001000
#define XSUSPEND_ON_COMP                   0x000002000
#define HANDOFF_ERROR_SYM                  'H'   /* NOT PART OF P1003.15D12! */
#define HANDOFF_ERROR                      0x000004000
#define SUBORDINATED_SYM                   'S'   /* NOT PART OF P1003.15D12! */
#define SUBORDINATED                       0x000008000
/* Keep_list Constants */
#define KEEP_NONE_SYM                      'n'
#define KEEP_NONE                          0x00000000
#define KEEP_STD_ERROR_SYM                 'e'
#define KEEP_STD_ERROR                     0x000010000
#define KEEP_STD_OUTPUT_SYM                'o'
#define KEEP_STD_OUTPUT                    0x000020000

/* Mail Option Constants */

#define MAIL_AT_ABORT_SYM                  'a'
#define MAIL_AT_ABORT                      0x000040000
#define MAIL_AT_BEGINNING_SYM              'b'
#define MAIL_AT_BEGINNING                  0x000080000
#define MAIL_AT_EXIT_SYM                   'e'
#define MAIL_AT_EXIT                       0x000100000
#define NO_MAIL_SYM                        'n'
#define NO_MAIL                            0x000200000
#define MAIL_AT_SUSPENSION_SYM             's'   /* NOT PART OF P1003.15D12! */
#define MAIL_AT_SUSPENSION                 0x000400000

/********************************************************************************/

/* User access declarations */

#define GLOBAL_ACCESS_LIST                "GLOBAL"  /* global access list name */
#define ACCESS_FREE                       1         /* access free w/o exclusions */
#define ACCESS_OPEN                       2         /* access open w/ exclusions */
#define ACCESS_RESTRICTED                 3         /* access restricted, some */
                                                    /* users allowed */
/*******************************************************************************/
/*   conf file definitions           */
#define LEAVE_OUTPUT_FILES    800
#define COPY_OUTPUT_FILES     801
#define LINK_OUTPUT_FILES     802

/********************************************************************************/

/* misc qsub/qsh stuff */

/* Resource request types */
#define GENERIC                          0   /* resource requested by DQS group */
#define HARD                             0   /* request must be satisfied */
#define SOFT                             2   /* request need not be satisfied */
#define SPECIFIC                         3   /* specific queue requested */

/* used by the parser */
#define MASTER                           0
#define H_SPECIFIC                       1
#define H_GENERIC                        2
#define S_SPECIFIC                       3
#define S_GENERIC                        4

#define P4                               1
#define MPI                              2
#define GENERIC_SLA                      3
#define GENERIC_ALL                      4
#define PVM                              5
#define TCGMSG                           6
/********************************************************************************/

/* misc directories */
/* these are all relative to the SPOOL_DIR */
#define COMMON_DIR           "common_dir"
#define EXEC_DIR             "exec_dir"
#define JOB_DIR              "job_dir"
#define QUEUE_DIR            "queue_dir"
#define RUSAGE_DIR           "rusage_dir"
#define TID_DIR              "tid_dir"

/* misc files */
/* these are all relative to the SPOOL_DIR */
#define ACL_FILE             "common_dir/acl_file"
#define ACT_FILE             "act_file"
#define PID_FILE             "pid_file"
#define COMPLEX_FILE         "common_dir/complex_file"
#define CONSUMABLE_FILE      "common_dir/consumable_file"
#define COOKIE_FILE          "common_dir/cookie_file"
#define DEFAULT_COMPLEX_FILE "common_dir/default_complex_file"
#define DEFAULT_QCONF_FILE   "common_dir/default_qconf_file"
#define GENERIC_QUEUE        "common_dir/generic_queue"
#define HOST_FILE            "common_dir/host_file"
#define MAN_FILE             "common_dir/man_file"
#define OP_FILE              "common_dir/op_file"
#define SEQ_NUM_FILE         "common_dir/seq_num_file"
#define STAT_FILE            "stat_file"

/*********************************************************/
/*Code via Doug Gibson*/
#define MAX_STRING_SIZE   2048

#define INTSIZE     4     /* (4) 8 bit bytes */
#if _UNICOS
#define INTOFF      4     /* big endian 64-bit machines where sizeof(int) = 8 */
#else
#define INTOFF      0     /* the rest of the world; see comments in request.c */
#endif

#define MAX_DBE_SIZE 4096 /* max (key,content) size in bytes for ndbm(3) */

#define REQUESTSIZE 1024   /* BE CAREFUL */

#define HASH_BUCKET_SIZE         128
#define QMASTER_HASH_BUCKET_SIZE 256
#ifndef MAX_NIS_RETRIES
#define MAX_NIS_RETRIES 10 /* max number of retries for slow NIS servers */
#endif
#ifndef MAX_UNLINK_RETRIES
#define MAX_UNLINK_RETRIES 50   /* max number of unlink(2) retries */
#endif

#define CLEAR_EXECD_TIDS   10 /* how often to clear unreaped execd TIDs */

/*********************************************************/
/* Operating system-specific definitions                 */
/*********************************************************/

#if ( defined(SOLARIS23) || defined(SOLARIS24) || defined(SOLARIS25) || defined(SOLARIS26) || defined(SOLARIS27) )
#define SOLARIS23_UP TRUE
#endif

/* Extended sysconf(2) interface macros */
#ifdef _SC_EXIT_SIGHUP
#define EXIT_SIGHUP sysconf(_SC_EXIT_SIGHUP)
#else
#define EXIT_SIGHUP FALSE
#endif
#ifdef _SC_PID_MAX
#define MAX_PROCESS_ID sysconf(_SC_PID_MAX)
#else
#define MAX_PROCESS_ID MAXPID
#endif
#ifdef _SC_UID_MAX
#define MAX_USER_ID sysconf(_SC_UID_MAX)
#else
#define MAX_USER_ID MAXUID
#endif

/* FLOCK - lock a file */

#if (defined(_AIX) || defined(__hpux) || defined(sun))
#define FLOCK(x) lockf(x,F_LOCK,0)
#define FUNLOCK(x) lockf(x,F_ULOCK,0)
#else
#define FLOCK(x) flock(x,LOCK_EX)
#define FUNLOCK(x) flock(x,LOCK_UN)
#endif


/* GETPGRP - get a process group */

#if (defined(__sgi) || defined(__convex__) || defined(_AIX) || defined(i386) || defined (SVR3) || defined (__osf__) || defined(solaris)|| defined(SOLARIS23_UP) )
#define GETPGRP getpgrp()
#else
#define GETPGRP getpgrp(getpid())
#endif

/* SETPGRP - set process group */
#if (defined(__sgi) || defined(i386) || defined(_UNICOS) || defined (SVR3)|| defined (__osf__) || defined (_AIX) || defined(solaris) || defined(SOLARIS23_UP) )
#define SETPGRP setpgrp()
#else
#define SETPGRP setpgid(getpid(), GETPGRP)
#endif

/* SunOS 4.1.X  Specific SETPGRP, Required for Proper Signal Handling. */
/* Assign calling process, PID=0, the Process Group ID, pgrp, to the actual */
/* PID number.  */
#if ( defined(sun) && !(defined(solaris) || defined(SOLARIS23_UP) ))
#undef SETPGRP
#define SETPGRP setpgrp(0,getpid())
#endif

#if defined( __FreeBSD__) 
#undef SETPGRP
#define SETPGRP setpgrp(getpid(),getpid())  
#endif 
/*This is a patch from David Geldreich*/
#if defined (__osf__)
#undef SETPGRP
#define SETPGRP setpgid(getpid(),getpid())
#endif
/*End patch*/
#if defined __hpux
#undef SETPGRP
#undef GETPGRP
#define SETPGRP setpgrp()
#define GETPGRP getpgrp()
#endif

#if (defined( linux ) && defined(__alpha ) )
#undef SETPGRP
#undef GETPGRP
#define SETPGRP setpgrp()
#define GETPGRP getpgrp()
#endif

#if defined __hpux
#define SETEUID(e1)  setresuid (-1, e1, -1)
#else
#define SETEUID(e1)  seteuid ( e1 )
#endif


/* SETPRIORITY - set process priority */
#if (defined(solaris)||defined(SOLARIS23_UP))
#define SETPRIORITY(niceval) nice(niceval-nice(0))
#endif
#ifdef __hpux
#define SETPRIORITY(niceval) nice(niceval)
#endif
#ifdef _UNICOS
#define SETPRIORITY(niceval) nice(niceval)
#endif
#ifndef SETPRIORITY
#define SETPRIORITY(niceval) setpriority(PRIO_PGRP,GETPGRP,niceval)
#endif

/* SunOS 4.1.X DOES NOT HAVE "strerror()" routine defined.  */
/* Forces the use of the "sys_errlist[]" structure defined in "<errno.h>".  */
#if ( defined(sun) && !(defined(solaris) || defined(SOLARIS23_UP) ))
#define STRERROR sys_errlist[(int) errno]
#else
#define STRERROR strerror((int) errno)
#endif

#if (defined(_UNICOS) || defined(__hpux) || defined(solaris) || defined(SOLARIS23_UP))
#define RESOURCES tms
#define GETRUSAGE(loc) times(loc)
#if _UNICOS
#define CLOCKTICK _SC_CLK_TCK
#endif

#if (defined(__hpux) || defined(solaris)|| defined(SOLARIS23_UP))
#define CLOCKTICK CLK_TCK;
#endif
#else
#define RESOURCES rusage
#define GETRUSAGE(loc) getrusage(RUSAGE_CHILDREN,loc)
#define CLOCKTICK
#endif

#if (defined( solaris) || defined(SOLARIS23_UP))
#ifdef bcmp
#undef bcmp
#endif
#define bcmp(s1, s2, n) memcmp ((s1), (s2), (n))

#ifdef bcopy
#undef bcopy
#endif
#define bcopy(s, d, n)  memcpy ((d), (s), (n))

#ifdef bzero
#undef bzero
#endif
#define bzero(s, n)     memset ((s), 0, (n))

#ifdef index
#undef index
#endif
#define index(s, c) strchr(s, c)

#ifdef rindex
#undef rindex
#endif
#define rindex(s, c) strrchr(s, c)

/* this is no longer used in solaris, but then we have no rusage-information */
#ifdef wait3
#undef wait3
#endif
#define wait3(s, o, r) waitpid(-1, s, o)

#endif


/* Directory structure definitions */

#if (defined(_AIX) || defined(__osf__) || defined(_UNICOS) || defined(sun) || defined(solaris) || defined(SOLARIS23_UP))
#define DIRENT dirent
        struct dirent *readdir();
#else
#define DIRENT direct
#ifndef NeXT
        struct direct *readdir();
#endif
#endif

/* Temporary filename interface */
#if __convex__
#define TEMPNAM tmpnam((char *)NULL)
char *tmpnam();
#else
#define TEMPNAM tempnam((char *)NULL,(char *)NULL)
char *tempnam();
#endif

#if (defined( linux ) && defined(__alpha ) )
#define ADDRLEN size_t 
#else 
#define ADDRLEN int  
#endif

#ifndef _NFILE
#define _NFILE 32
#endif

/*********************************************************/
/* Logging macros from hell                              */
/*********************************************************/

#define FREE(x) if(x){free( (char *)x); x=NULL;}

#define READ_WRITE_MACRO_DEFS int str_len=0;int bytes_written=0;\
int ii=0;int bytes_read=0;string tmpp_str

#define WRITE_INT(x,y) if (dqs_writenbytes(x,y,INTSIZE)!=INTSIZE) {\
WARNING((DQS_EVENT,"dqs_writenbytes() returned an error"));\
DEXITE;return(-1);}else{bytes_written+=INTSIZE;}

#define WRITE_STR(x,y) str_len=strlen(y);str_len++;\
WRITE_INT(x,&str_len);ii=dqs_writenbytes(x,y,str_len);\
DPRINTF((DQS_EVENT,"dqs_writenbytes returned %d str_len = %d",ii,str_len))\
if (ii!=str_len) {WARNING((DQS_EVENT,"error writting string"));\
DEXITE;return(-1);}else{bytes_written+=str_len;}

#define READ_INT(x,y) if (dqs_readnbytes(x,y,INTSIZE)!=INTSIZE) {\
WARNING((DQS_EVENT,"dqs_readnbytes() returned an error"));DEXITE;return(NULL);}\
else{bytes_read+=INTSIZE;}

#define READ_STR(x,y)READ_INT(x,&str_len);ii=dqs_readnbytes(x,tmpp_str,str_len);if(ii!=str_len){\
WARNING((DQS_EVENT,"error reading string"));DEXITE;return(NULL);}\
else{y=dqs_string_insert(y,tmpp_str);bytes_read+=str_len;}

/* DON'T TOUCH THESE! */
#define NIBBLE 8
#define OFFSET 16*NIBBLE
#define CHUNK  262144
#define NIBBLE_SIZE(x) ((1+((x-1)/NIBBLE))*NIBBLE)

#define CHUNK_SIZE(x) ((1+((x-1)/CHUNK))*CHUNK)

#define PACK_MACRO_DEFS int STR_LEN;char STRING[MAX_STRING_SIZE];u_long32 J

/*           a      b     c       d          e
PACKINT(head_ptr,cur_ptr,int,bytes_packed,mem_size);
*/

#define PACKINT(a,b,c,d,e)\
   if ((d+INTSIZE)>e)\
   {\
      e+=CHUNK;\
      a=dqs_realloc(a,e);\
      if (!a)\
      {\
           CRITICAL((DQS_EVENT,"dqs_realloc() failure in PACKINT()"));\
           abort();\
      }\
      b=(a);\
      b+=(d);\
   }\
   J=htonl(c);\
   bcopy(&J,b,INTSIZE);\
   b=(b+INTSIZE);\
   d+=INTSIZE;


/*          a       b     c       d          e
PACKSTR(head_ptr,cur_ptr,str,bytes_packed,mem_size);
*/


#define PACKSTR(a,b,c,d,e)\
   if (!c) STR_LEN=1; \
   else { \
   STR_LEN=strlen(c);\
   STR_LEN++; } \
   if ((d+STR_LEN)>e)\
   {\
      e+=CHUNK;\
      a=dqs_realloc(a,e);\
      if (!a)\
      {\
           CRITICAL((DQS_EVENT,"dqs_realloc() failure in PACKSTR()"));\
           abort();\
      }\
      b=(a);\
      b+=(d);\
   }\
   if (c) bcopy(c,b,STR_LEN);\
   else bcopy(&dqs_zero,b,STR_LEN); \
   b+=STR_LEN;\
   d+=STR_LEN;

/*          a       b       c       d          e          f
PACKBUF(head_ptr,cur_ptr,buf_ptr,buf_size,bytes_packed,mem_size);
*/

#define PACKBUF(a,b,c,d,e,f)\
   if ((d+e)>f)\
   {\
     f+=CHUNK_SIZE(d);\
     a=dqs_realloc(a,f);\
      if (!a)\
      {\
           CRITICAL((DQS_EVENT,"dqs_realloc() failure in PACKBUF()"));\
           abort();\
      }\
     b=(a);\
     b+=(e);\
   }\
   bcopy(c,b,d);\
   b+=(d);\
   e+=(d);


/*           a     b       c              d
UNPACKINT(cur_ptr,int,bytes_unpacked,bytes_packed);
*/
#define UNPACKINT(a,b,c,d)\
   if ((c+INTSIZE)>d)\
   {\
      CRITICAL((DQS_EVENT,"error in UNPACKINT()"));\
      abort();\
   }\
   bcopy(a,&b,INTSIZE);\
   b=ntohl(b);\
   a+=INTSIZE;\
   c+=INTSIZE;


/*           a     b       c              d
UNPACKSTR(cur_ptr,str,bytes_unpacked,bytes_packed);
*/
#define UNPACKSTR(a,b,c,d)\
   if (!a[0]) STR_LEN=1; \
   else { \
   STR_LEN=strlen(a);\
   STR_LEN++;\
   } \
   if ((STR_LEN+c)>d)\
   {\
      CRITICAL((DQS_EVENT,"error in UNPACKSTR()"));\
      abort();\
   }\
   FREE(b); \
if (a[0]) { \
   bcopy(a,STRING,STR_LEN);\
   b=dqs_string_insert(NULL,STRING); } \
   else b=NULL; \
   a+=STR_LEN;\
   c+=STR_LEN;

/*           a       b       c          d              e
UNPACKBUF(cur_ptr,buf_ptr,buf_size,bytes_unpacked,bytes_packed);
*/

#define UNPACKBUF(a,b,c,d,e)\
   if ((c+d)>e)\
   {\
     CRITICAL((DQS_EVENT,"error in UNPACKBUF()"));\
     abort();\
   }\
   b=dqs_malloc(c);\
   bcopy(a,b,c);\
   a+=c;\
   d+=c;


#define CRITICAL(x) sprintf x;dqs_log(LOG_CRIT,DQS_EVENT,__FILE__,DQS_FUNC,__LINE__)
#define ERROR(x)    sprintf x;dqs_log(LOG_ERR,DQS_EVENT,__FILE__,DQS_FUNC,__LINE__)
#define WARNING(x)  sprintf x;dqs_log(LOG_WARNING,DQS_EVENT,__FILE__,DQS_FUNC,__LINE__)
#define NOTICE(x)   sprintf x;dqs_log(LOG_NOTICE,DQS_EVENT,__FILE__,DQS_FUNC,__LINE__)
#define INFO(x)     sprintf x;dqs_log(LOG_INFO,DQS_EVENT,__FILE__,DQS_FUNC,__LINE__)

#ifdef DQS_COMPILE_DEBUG 

#define DENTER_MAIN(x) \
   int LOG_LEVEL=LOG_DEBUG,DQS_OINDENT; \
   string DQS_FUNC,DQS_EVENT,ACK_EVENT; \
   dqs_list_type LISTEL; \
   bzero((char *)&conf,sizeof(conf)); \
   bzero((char *)&me,sizeof(me)); \
   conf.logfacility=LOGFACILITY; \
   DQS_FUNC[0]=0;\
   dqs_mini_setup(argv[0]); \
   if (getenv("EXT_DEBUG")) \
       {DEBUG_LOGLEVEL=LOG_EXTDEBUG;DEBUG_ON=TRUE;} \
   else if (getenv("DEBUG")) \
       {DEBUG_LOGLEVEL=LOG_DEBUG;DEBUG_ON=TRUE;} \
   else \
       DEBUG_LOGLEVEL=0; \
   if (DEBUG_ON)\
   {\
      strcpy x;\
      strcpy(DQS_FUNC,DQS_EVENT);\
      DQS_OINDENT=DEBUG_INDENT;\
      DEBUG_INDENT+=8;\
      sprintf(DQS_EVENT,"--> %s()",DQS_FUNC);\
      dqs_log(LOG_LEVEL,DQS_EVENT,__FILE__,DQS_FUNC,__LINE__);\
   }

#define DENTER(x)\
   int  LOG_LEVEL=LOG_DEBUG,DQS_OINDENT; \
   string DQS_FUNC,DQS_EVENT,ACK_EVENT; \
   dqs_list_type LISTEL; \
   DQS_FUNC[0]=0;\
   if (EXT_DEBUG_ON|DEBUG_ON)\
   {\
      strcpy x;\
      strcpy(DQS_FUNC,DQS_EVENT);\
      DQS_OINDENT=DEBUG_INDENT;\
      DEBUG_INDENT+=8;\
      sprintf(DQS_EVENT,"--> %s()",DQS_FUNC);\
      dqs_log(LOG_LEVEL,DQS_EVENT,__FILE__,DQS_FUNC,__LINE__);\
   }

#define DENTER_EXT(x)\
   int  LOG_LEVEL=LOG_EXTDEBUG,DQS_OINDENT; \
   string DQS_FUNC,DQS_EVENT,ACK_EVENT; \
   dqs_list_type LISTEL; \
   DQS_FUNC[0]=0;\
   if (EXT_DEBUG_ON|DEBUG_ON)\
   {\
      strcpy x;\
      strcpy(DQS_FUNC,DQS_EVENT);\
      DQS_OINDENT=DEBUG_INDENT;\
      DEBUG_INDENT+=8; \
      sprintf(DQS_EVENT,"--> %s()",DQS_FUNC);\
      dqs_log(LOG_LEVEL,DQS_EVENT,__FILE__,DQS_FUNC,__LINE__);\
   }

#define DPRINTF(x)\
   if (DEBUG_ON)\
   {\
     sprintf x;\
     dqs_log(LOG_LEVEL,DQS_EVENT,__FILE__,DQS_FUNC,__LINE__);\
   } 

#define DTRACE\
   if (DEBUG_ON)\
   {\
     sprintf(DQS_EVENT,"TRACE");\
     dqs_log(LOG_LEVEL,DQS_EVENT,__FILE__,DQS_FUNC,__LINE__);\
   }

#define DTRACEE\
   if (1)\
{\
     sprintf(DQS_EVENT,"TRACE");\
     dqs_log(LOG_ERR,DQS_EVENT,__FILE__,DQS_FUNC,__LINE__);\
}

#define ACK(x)\
     sprintf x;\
     bzero((char *)&LISTEL,sizeof(LISTEL));\
     LISTEL.status=DQS_ACK;\
     LISTEL.str0=dqs_string_insert(NULL,ACK_EVENT);\
     reply_head=dqs_insert(DQS_STR0,TAIL,reply_head,&LISTEL);

#define NAK(x)\
     sprintf x;\
     bzero((char *)&LISTEL,sizeof(LISTEL));\
     LISTEL.status=DQS_NAK;\
     LISTEL.str0=dqs_string_insert(NULL,ACK_EVENT);\
     reply_head=dqs_insert(DQS_STR0,TAIL,reply_head,&LISTEL);

#define DEXIT\
   if (DEBUG_ON)\
   {\
     sprintf(DQS_EVENT,"<-- %s()",DQS_FUNC);\
     dqs_log(LOG_LEVEL,DQS_EVENT,__FILE__,DQS_FUNC,__LINE__);\
     DEBUG_INDENT=DQS_OINDENT;\
   }

#define DEXITE\
   if (DEBUG_ON)\
   {\
     sprintf(DQS_EVENT,"<-- %s() *** ERROR ***",DQS_FUNC);dqs_log(LOG_LEVEL,DQS_EVENT,__FILE__,DQS_FUNC,__LINE__);\
     DEBUG_INDENT=DQS_OINDENT;\
   }

#else 
#define DENTER(x) {}
#define DTRACE    {}
#define DPRINTF(x){} 
#define DEXIT     {}
#endif


#if defined(_AIX) || defined(SVR3)
#define DQS_ASSERT(x)  if x ; else {dqs_log(LOG_CRIT, # x ,__FILE__,DQS_FUNC,__LINE__);dqs_log(LOG_CRIT,"unrecoverable error - contact systems manager",__FILE__,DQS_FUNC,__LINE__);abort();}
#else
#define DQS_ASSERT(x)  if x ; else {dqs_log(LOG_CRIT,"unrecoverable error - contact systems manager",__FILE__,DQS_FUNC,__LINE__);abort();}
#endif

#define DQS_EXIT(x)\
     if (x==DQS_ACK)\
     exit(0);\
     else\
     exit(-1);

/******************************************************************************/
/* misc flags/attribute defines */

#define NO_OPT         0
#define a_OPT          1
#define A_OPT          2
#define B_OPT          3
#define c_OPT          4
#define cell_OPT       5
#define C_OPT          6
#define e_OPT          7
#define par_OPT        8
#define E_OPT          9
#define f_OPT          10
#define h_OPT          11
#define hard_OPT       12
#define j_OPT          13
#define k_OPT          14
#define l_OPT          15
#define m_OPT          16
#define master_OPT     17
#define M_OPT          18
#define N_OPT          19
#define o_OPT          20
#define O_OPT          21
#define p_OPT          22
#define q_OPT          23
#define Q_OPT          24
#define r_OPT          25
#define s_OPT          26
#define soft_OPT       27
#define S_OPT          28
#define u_OPT          29
#define v_OPT          30
#define verify_OPT     31
#define V_OPT          32
#define z_OPT          33
#define DESTIN_OPR     34
#define JOB_ID_OPR     35
#define MESSAGE_OPR    36
#define SCRIPT_OPR     37
#define SRVR_NM_OPR    38
#define soc_OPT        39
#define xsoc_OPT       40
#define help_OPT       41
#define cwd_OPT        42
#define ext_OPT        43
#define ul_OPT         44
#define reauth_OPT     45
#define notify_OPT     46
#define passwd_OPT     47
#define Passwd_OPT     48
#define d_OPT          49
#define us_OPT         50
#define hold_jid_OPT   51

#define ac_OPT         101
#define ah_OPT         102
#define am_OPT         103
#define ao_OPT         104
#define aq_OPT         105
#define au_OPT         106
#define Aq_OPT         107
#define cq_OPT         108
#define dc_OPT         109
#define dh_OPT         110
#define dm_OPT         111
#define do_OPT         112
#define dq_OPT         113
#define du_OPT         114
#define kq_OPT         115
#define kqs_OPT        116
#define mc_OPT         117
#define mconf_OPT      118
#define mq_OPT         119
#define qmon_OPT       120
#define sc_OPT         121
#define scl_OPT        122
#define sconf_OPT      123
#define sh_OPT         124
#define sm_OPT         125
#define so_OPT         126
#define sq_OPT         127
#define sql_OPT        128
#define su_OPT         129
#define sul_OPT        130
#define srl_OPT        131
#define jid_OPT        132
#define clean_OPT      133
#define gc_OPT         134  /* dummy from qconf to qmasster to get complex */
#define acons_OPT      135  /* add consumable */
#define mcons_OPT      136  /*  modify consumable */
#define dcons_OPT      137  /*  delete consumable */
#define scons_OPT      138
#define sconsl_OPT     139
#define gcons_OPT      140
#define refr_OPT       141  /* refresh dqs_execd  */
#define shutd_OPT      142  /*  shutdown dqs_execd */
#define rc_OPT         143  /* return consumable   */
#define F_OPT          144  /* force submission of a job (qsub ) */
#define g_OPT		   145  /* geometry option   */
/* who */
#define QALTER          1
#define QCONF           2
#define QDEL            3
#define QHOLD           4
#define QIDLE           5
#define QMASTER         6
#define QMOD            7
#define QMOVE           8
#define QMSG            9
#define QRERUN          10
#define QRLS            11
#define QSELECT         12
#define QSH             13
#define QSIG            14
#define QSTAT           15
#define QSUB            16
#define DQS_EXECD       17
#define MAX_ANCILLARY   17
#define ALL_OPT         19

/* Note: do not include QUSAGE before ALL_OPT! */
/* ALL_OPT is used by "dqs_options" while "qusage" */
/* is part of "XSRC" */

#define QUSAGE          20
#define DCMD            21
#define DSH             22

/* macros used in parsing */
#define VALID_OPT(opt,who) (dqs_options[opt][who])

/****************************************************************/
/* DQS list types */

#define DQS_TYPE            0x00000001
#define DQS_INT0            0x00000002
#define DQS_INT1            0x00000004
#define DQS_INT2            0x00000010
#define DQS_INT3            0x00000020
#define DQS_STR0            0x00000040
#define DQS_STR1            0x00000100
#define DQS_STR2            0x00000200
#define DQS_STR3            0x00000400
#define DQS_RUSAGE          0x00001000
#define DQS_QUEUE           0x00002000
#define DQS_CONF            0x00004000
#define DQS_JOB             0x00010000
#define DQS_ME              0x00020000
#define DQS_CHAIN           0x00040000

#define DQS_STDIN           0x00100000
#define DQS_STDOUT          0x00200000
#define DQS_STDERR          0x00400000
#define DQS_DEBUG           0x01000000
#define DQS_HOSTS           0x02000000
#define DQS_SHELL           0x04000000
#define DQS_ACCOUNT         0x10000000
#define DQS_PAR_STDOUT      0x20000000
#define DQS_PAR_STDERR      0x40000000

/*patch from Ron Lee*/
#define VALID(a,b) ((a)&(b))   
#define SETBIT(a,b) ((b)=(a)|(b));
#define CLEARBIT(a,b) ((b)=~(a)&(b));


/****************************************************************/
/* DQS "op" types */

#define EQ_OP               0x00000001
#define GE_OP               0x00000002
#define GT_OP               0x00000004
#define LT_OP               0x00000008
#define LE_OP               0x00000010
#define NE_OP               0x00000020
#define NOT_OP              0x00000040
#define AND_OP              0x00000080
#define OR_OP               0x00000100
#define STREQ_OP            0x00000200
#define END_OP              0x00001000
/****************************************************************/
/* misc */

#define GRANTED             0
#define REAPED              3
#define SLAVE               1
#define MIN_BACKOFF_TIME    2
#define MAX_BACKOFF_TIME    10
#define ABORT               -1
#define NEGATE_CLASS        '^'
/*Code via Doug Gibson*/
#define TOKEN_SIZE          2048
#define MAX_KEY_SIZE        100
#define DQS_NRETRIES        3
#define MAX_KLOG_TIME       15
#define DQS_MAXNAMELEN      MAX_STRING_SIZE /* Max str length allowed in dsh/dshd */
#define MAX_RLIMIT          0x7fffffff

/****************************************************************/
/* DQS Format Macros */

#define STATFILE_FPRINTF_FORMAT "%d:%s:%s:%d:%d:%d:%s:%s\n"

#define STATFILE_FSCANF_FORMAT "\n%d:%[^:]:%[^:]:%d:%d:%d:%[^:]:%[^:\n]"

#define STATFILE_FSCANF_COUNT 8

#define STATFILE_FSCANF_VARS \
             &Stats->time, \
             Stats->qname, \
             Stats->hostname, \
             &Stats->load_avg, \
             &Stats->qty, \
             &Stats->qty_active, \
             qcomplex_str, \
             Stats->states

#define ACTFILE_FPRINTF_FORMAT \
"%s:%s:%ld:%s:%s:%s:%s:%s:%s:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld\n"

#define ACTFILE_FSCANF_FORMAT \
"\n%[^:]:%[^:]:%ld:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld:%ld"

#define ACTFILE_FSCANF_COUNT 33

#define ACTFILE_FPRINTF_VARS \
             d->qname, \
             d->hostname, \
             d->master, \
             qcomplex_str, \
             d->group, \
             d->owner, \
             d->job_name, \
             d->dqs_job_name, \
             d->account, \
             d->priority, \
             d->job_number, \
             d->submission_time, \
             d->start_time, \
             d->end_time, \
             d->exit_status, \
             d->ru_wallclock, \
             d->ru_utime, \
             d->ru_stime, \
             d->ru_maxrss, \
             d->ru_ixrss, \
             d->ru_ismrss, \
             d->ru_idrss, \
             d->ru_isrss, \
             d->ru_minflt, \
             d->ru_majflt, \
             d->ru_nswap, \
             d->ru_inblock, \
             d->ru_oublock, \
             d->ru_msgsnd, \
             d->ru_msgrcv, \
             d->ru_nsignals, \
             d->ru_nvcsw, \
             d->ru_nivcsw

#define ACTFILE_FSCANF_VARS \
             d->qname, \
             d->hostname, \
             &d->master, \
             qcomplex_str, \
             d->group, \
             d->owner, \
             d->job_name, \
             d->dqs_job_name, \
             d->account, \
             &d->priority, \
             &d->job_number, \
             &d->submission_time, \
             &d->start_time, \
             &d->end_time, \
             &d->exit_status, \
             &d->ru_wallclock, \
             &d->ru_utime, \
             &d->ru_stime, \
             &d->ru_maxrss, \
             &d->ru_ixrss, \
             &d->ru_ismrss, \
             &d->ru_idrss, \
             &d->ru_isrss, \
             &d->ru_minflt, \
             &d->ru_majflt, \
             &d->ru_nswap, \
             &d->ru_inblock, \
             &d->ru_oublock, \
             &d->ru_msgsnd, \
             &d->ru_msgrcv, \
             &d->ru_nsignals, \
             &d->ru_nvcsw, \
             &d->ru_nivcsw

/****************************************************************/
/* DQS Development Macros */

#define GETFD(a) close(creat("RMME",0755));a=open("RMME",O_RDWR)

#define RESETFD(a) lseek(a,0,SEEK_SET) 

#if (defined(sun) || defined(solaris) || defined(SOLARIS23_UP))
#define volatile   /* comment this out if a real compiler */
#define labs abs   /* ditto - way to go SUN! */
#endif

#ifdef NeXT
#define sigaction sigvec
#define sa_handler sv_handler
#define sa_mask    sv_mask
#define sa_flags   sv_flags   
#define sigset_t int
#endif

#ifndef pid_t
#define pid_t int
#endif

#ifndef gid_t
#define gid_t int
#endif

#ifndef mode_t
#define mode_t int
#endif

/* 
   this isn't the way to do it but since I've yet to figure out
   how you are suppose to differentiate SunOS 4/5...

   course the SunPro demo compiler I saw doesn't define "__svr4__"

   funny how it only takes a hour to port to every other arc,
   (all totalled!) then you spend days porting to SunOSes
 */

#ifdef __svr4__
#ifdef sun 
#define sloaris
#endif
#endif
