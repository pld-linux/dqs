#define STATIC_CONFIGURATION      FALSE
#define CONF_FILE                 "/etc/dqs/conf_file"
#define RESOLVE_FILE              "/etc/dqs/resolve_file"
#define KEY_FILE                  "/etc/dqs/key_file"
#define AFS                       FALSE
#define ERR_FILE                  "/var/log/dqs/err_file"
#define LOG_FILE                  "/var/log/dqs/log_file"
#define QMASTER_SPOOL_DIR         "/var/spool/dqs"
#define EXECD_SPOOL_DIR           "/var/spool/dqs"
#define DEFAULT_CELL              "localdomain"
#define RESERVED_PORT             TRUE
#define DQS_EXECD_SERVICE         "dqs_execd"
#define QMASTER_SERVICE           "dqs_qmaster"
#define INTERCELL_SERVICE         "dqs_intercell"
#define KLOG                      "/usr/local/bin/klog"
#define REAUTH_TIME               60
#define MAILER                    "/bin/mail"
#define DQS_BIN                   "/usr/bin"
#define ADMINISTRATOR             "postmater@localhost"
#define DEFAULT_ACCOUNT           "GENERAL"
#define DEFAULT_HOST              "localhost"
#define LOGMAIL                   FALSE
#define DEFAULT_RERUN             FALSE
#define DEFAULT_SORT_SEQ_NO       FALSE
#define SYNC_IO                   FALSE
#define USER_ACCESS               ACCESS_FREE
#define LOGFACILITY               LOG_VIA_SYSLOG
#define LOGLEVEL                  LOG_INFO
#define MIN_UID                   1000
#define MIN_GID                   100
#define MAXUJOBS                  100
#define OUTPUT_HANDLING           LEAVE_OUTPUT_FILES
#define ADDON_SCRIPT              NONE
#define ADDON_INFO                NONE
#define LOAD_LOG_TIME             30
#define STAT_LOG_TIME             600
#define SCHEDULE_TIME             60
#define MAX_UNHEARD               90
#define ALARMS                    3
#define ALARMM                    3
#define ALARML                    3
#define MAIL_HAS_SUBJ_LINE        TRUE
#define DEFAULT_MANAGER           "root"
#define PVM_ROOT                  ""
#ifdef SUN
#define volatile
#define labs abs
#endif
#define SLAVE_LOOP_TIME           "200"
#define LINK_FILE_PATH            ""
#define COPY_FILE_DELAY           "300"
/* To use the link strategy you must ensure, that                  */
/* (1) a file with the value of TMP_LINK_OUTPUT_FILES exists in    */
/*     the directory EXECD_SPOOL_DIR and contains the required     */
 /*     global path to the directory EXECD_SPOOL_DIR/local.         */
 /*     To be able to access this directory from any node via       */
 /*     NFS/AFS it is referenced using the contents of the file     */
 /*              EXECD_SPOOL_DIR/TMP_LINK_OUTPUT_FILES              */
 /*     as the head of the pathname. For example:                   */
 /*       We use the NFS automounter and have any EXECD_SPOOL_DIR   */
 /*       imported as /import/dqs_execd_spool.<hostname> where      */
 /*       hostname is the name of the involved worker node.         */
 /*       So we created on the worker node 'rznb1' a file           */
 /*           EXECD_SPOOL_DIR/netpath                               */
 /*       with the contents                                         */
 /*           /import/dqs_execd_spool.rznb1                         */
 /*       and set the above #define to                              */
 /*           #define TMP_LINK_OUTPUT_FILES 'netpath'               */
 /* (2) all directories EXECD_SPOOL_DIR are accessible from each    */
 /*     node a user can place his output files                      */
 /*-----------------------------------------------------------------*/
