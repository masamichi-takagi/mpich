[#] start of __file__

AC_DEFUN([PAC_SUBCFG_PREREQ_]PAC_SUBCFG_AUTO_SUFFIX,[
	PAC_SET_HEADER_LIB_PATH(hcoll)
	PAC_CHECK_HEADER_LIB([hcoll/api/hcoll_api.h],[hcoll],[hcoll_init],[have_hcoll=yes],[have_hcoll=no])
	AM_CONDITIONAL([BUILD_HCOLL],[test "$have_hcoll" = "yes"])
])dnl end PREREQ

AC_DEFUN([PAC_SUBCFG_BODY_]PAC_SUBCFG_AUTO_SUFFIX,[
# nothing to do
])dnl end _BODY

[#] end of __file__
