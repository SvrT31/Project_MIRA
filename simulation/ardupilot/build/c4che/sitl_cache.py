AP_LIBRARIES = ['AP_DroneCAN', 'modules/DroneCAN/libcanard/*.c', 'AP_HAL_SITL', 'AP_CSVReader', 'SITL', 'AP_Scripting', 'AP_Scripting/lua/src', 'AC_CustomControl']
AP_LIBRARIES_OBJECTS_KW = {}
AP_LIB_EXTRA_CFLAGS = {}
AP_LIB_EXTRA_CXXFLAGS = {}
AP_LIB_EXTRA_SOURCES = {'AP_Scripting': ['lua_generated_bindings.cpp']}
AR = ['/usr/bin/ar']
ARFLAGS = ['rcs']
BINDIR = '/usr/bin'
BOARD = 'sitl'
BOOTLOADER = False
BUILD_SUMMARY_HEADER = ['target', 'size_text', 'size_data', 'size_bss', 'size_total', 'size_free_flash', 'ext_flash_used']
CC = ['/usr/bin/gcc']
CCLNK_SRC_F = []
CCLNK_TGT_F = ['-o']
CC_NAME = 'gcc'
CC_SRC_F = []
CC_TGT_F = ['-c', '-o']
CC_VERSION = ('9', '4', '0')
CFLAGS = ['-ffunction-sections', '-fdata-sections', '-fsigned-char', '-Wall', '-Wextra', '-Werror=format', '-Wpointer-arith', '-Wcast-align', '-Wno-missing-field-initializers', '-Wno-unused-parameter', '-Wno-redundant-decls', '-Wno-unknown-pragmas', '-Wno-trigraphs', '-Werror=shadow', '-Werror=return-type', '-Werror=unused-result', '-Werror=unused-variable', '-Werror=narrowing', '-Werror=attributes', '-Werror=overflow', '-Werror=parentheses', '-Werror=format-extra-args', '-Werror=ignored-qualifiers', '-Werror=undef', '-DARDUPILOT_BUILD', '-Wno-format-contains-nul', '-fsingle-precision-constant', '-g', '-O0', '-DCANARD_64_BIT=1', '-MMD']
CFLAGS_MACBUNDLE = ['-fPIC']
CFLAGS_cshlib = ['-fPIC']
COMPILER_CC = 'gcc'
COMPILER_CXX = 'g++'
CONFIGURE_FILES = ['/home/svrt_31/ardusub/ardupilot/libraries/AP_Scripting/wscript', '/home/svrt_31/ardusub/ardupilot/libraries/AP_GPS/wscript', '/home/svrt_31/ardusub/ardupilot/libraries/AP_HAL_SITL/wscript', '/home/svrt_31/ardusub/ardupilot/libraries/SITL/wscript', '/usr/lib/python3.8/importlib/_bootstrap.py', '/usr/lib/python3.8/importlib/_bootstrap_external.py', '/usr/lib/python3.8/codecs.py', '/usr/lib/python3.8/encodings/aliases.py', '/usr/lib/python3.8/encodings/__init__.py', '/usr/lib/python3.8/encodings/utf_8.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waf-light', '/usr/lib/python3.8/encodings/latin_1.py', '/usr/lib/python3.8/abc.py', '/usr/lib/python3.8/io.py', '/usr/lib/python3.8/stat.py', '/usr/lib/python3.8/_collections_abc.py', '/usr/lib/python3.8/genericpath.py', '/usr/lib/python3.8/posixpath.py', '/usr/lib/python3.8/os.py', '/usr/lib/python3.8/_sitebuiltins.py', '/usr/lib/python3.8/_bootlocale.py', '/home/svrt_31/.local/lib/python3.8/site-packages/_distutils_hack/__init__.py', '/usr/lib/python3.8/types.py', '/usr/lib/python3.8/warnings.py', '/usr/lib/python3.8/importlib/__init__.py', '/usr/lib/python3.8/importlib/machinery.py', '/usr/lib/python3.8/importlib/abc.py', '/usr/lib/python3.8/operator.py', '/usr/lib/python3.8/keyword.py', '/usr/lib/python3.8/heapq.py', '/usr/lib/python3.8/reprlib.py', '/usr/lib/python3.8/collections/__init__.py', '/usr/lib/python3.8/functools.py', '/usr/lib/python3.8/contextlib.py', '/usr/lib/python3.8/importlib/util.py', '/usr/lib/python3/dist-packages/mpl_toolkits/__init__.py', '/usr/lib/python3/dist-packages/apport_python_hook.py', '/usr/lib/python3.8/sitecustomize.py', '/usr/lib/python3.8/site.py', '/usr/lib/python3.8/lib-dynload/_opcode.cpython-38-x86_64-linux-gnu.so', '/usr/lib/python3.8/opcode.py', '/usr/lib/python3.8/dis.py', '/usr/lib/python3.8/collections/abc.py', '/usr/lib/python3.8/enum.py', '/usr/lib/python3.8/sre_constants.py', '/usr/lib/python3.8/sre_parse.py', '/usr/lib/python3.8/sre_compile.py', '/usr/lib/python3.8/copyreg.py', '/usr/lib/python3.8/re.py', '/usr/lib/python3.8/token.py', '/usr/lib/python3.8/tokenize.py', '/usr/lib/python3.8/linecache.py', '/usr/lib/python3.8/inspect.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/__init__.py', '/usr/lib/python3.8/__future__.py', '/usr/lib/python3.8/shlex.py', '/usr/lib/python3.8/fnmatch.py', '/usr/lib/python3.8/_compression.py', '/usr/lib/python3.8/_weakrefset.py', '/usr/lib/python3.8/threading.py', '/usr/lib/python3.8/lib-dynload/_bz2.cpython-38-x86_64-linux-gnu.so', '/usr/lib/python3.8/bz2.py', '/usr/lib/python3.8/lib-dynload/_lzma.cpython-38-x86_64-linux-gnu.so', '/usr/lib/python3.8/lzma.py', '/usr/lib/python3.8/shutil.py', '/usr/lib/python3.8/traceback.py', '/usr/lib/python3.8/datetime.py', '/usr/lib/python3.8/platform.py', '/usr/lib/python3.8/struct.py', '/usr/lib/python3.8/base64.py', '/usr/lib/python3.8/signal.py', '/usr/lib/python3.8/_compat_pickle.py', '/usr/lib/python3.8/pickle.py', '/usr/lib/python3.8/selectors.py', '/usr/lib/python3.8/subprocess.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Errors.py', '/usr/lib/python3.8/lib-dynload/_hashlib.cpython-38-x86_64-linux-gnu.so', '/usr/lib/python3.8/hashlib.py', '/usr/lib/python3.8/encodings/hex_codec.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Utils.py', '/usr/lib/python3.8/weakref.py', '/usr/lib/python3.8/copy.py', '/usr/lib/python3.8/lib-dynload/_ctypes.cpython-38-x86_64-linux-gnu.so', '/usr/lib/python3.8/ctypes/_endian.py', '/usr/lib/python3.8/ctypes/__init__.py', '/usr/lib/python3.8/lib-dynload/termios.cpython-38-x86_64-linux-gnu.so', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/ansiterm.py', '/usr/lib/python3.8/string.py', '/usr/lib/python3.8/logging/__init__.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Logs.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/ConfigSet.py', '/usr/lib/python3.8/bisect.py', '/usr/lib/python3.8/random.py', '/usr/lib/python3.8/tempfile.py', '/usr/lib/python3.8/textwrap.py', '/usr/lib/python3.8/locale.py', '/usr/lib/python3.8/gettext.py', '/usr/lib/python3.8/optparse.py', '/usr/lib/python3.8/imp.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Node.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Context.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Options.py', '/usr/lib/python3.8/lib-dynload/_queue.cpython-38-x86_64-linux-gnu.so', '/usr/lib/python3.8/queue.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Task.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Runner.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/TaskGen.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Build.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Configure.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Scripting.py', '/usr/lib/python3.8/lib-dynload/_json.cpython-38-x86_64-linux-gnu.so', '/usr/lib/python3.8/json/scanner.py', '/usr/lib/python3.8/json/decoder.py', '/usr/lib/python3.8/json/encoder.py', '/usr/lib/python3.8/json/__init__.py', '/home/svrt_31/ardusub/ardupilot/Tools/ardupilotwaf/ap_persistent.py', '/home/svrt_31/ardusub/ardupilot/Tools/ardupilotwaf/ardupilotwaf.py', '/home/svrt_31/ardusub/ardupilot/Tools/ardupilotwaf/boards.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/__init__.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/c_aliases.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/c_preproc.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/c_config.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/c_osx.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/c_tests.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/ccroot.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/compiler_cxx.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/ar.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/gxx.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/clangxx.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/icpc.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/compiler_c.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/extras/__init__.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/xlc.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/extras/c_bgxlc.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/gcc.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/extras/c_emscripten.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/extras/c_nec.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/clang.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/icc.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/waf_unit_test.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/python.py', '/home/svrt_31/ardusub/ardupilot/Tools/ardupilotwaf/build_summary.py', '/home/svrt_31/ardusub/ardupilot/Tools/ardupilotwaf/ap_library.py', '/home/svrt_31/ardusub/ardupilot/Tools/ardupilotwaf/toolchain.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/cxx.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/Tools/c.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/extras/gccdeps.py', '/home/svrt_31/ardusub/ardupilot/Tools/ardupilotwaf/cxx_checks.py', '/usr/lib/python3.8/pipes.py', '/home/svrt_31/ardusub/ardupilot/modules/waf/waflib/extras/clang_compilation_database.py', '/usr/lib/python3.8/xml/__init__.py', '/usr/lib/python3.8/xml/etree/__init__.py', '/usr/lib/python3.8/xml/etree/ElementPath.py', '/usr/lib/python3.8/xml/etree/ElementTree.py', '/home/svrt_31/ardusub/ardupilot/Tools/ardupilotwaf/mavgen.py', '/home/svrt_31/ardusub/ardupilot/Tools/ardupilotwaf/dronecangen.py', '/home/svrt_31/ardusub/ardupilot/Tools/ardupilotwaf/git_submodule.py', '/home/svrt_31/ardusub/ardupilot/Tools/ardupilotwaf/gtest.py', '/home/svrt_31/ardusub/ardupilot/Tools/ardupilotwaf/static_linking.py', '/home/svrt_31/ardusub/ardupilot/wscript']
CONFIGURE_HASH = b'\x12\xf9\xee7\xbb\x0c\x8b&\xde[FQ~z\xee\x1b'
COVERAGE = False
CPPPATH_ST = '-I%s'
CXX = ['/usr/bin/g++']
CXXFLAGS = ['-Werror=implicit-fallthrough', '-fcheck-new', '-fsingle-precision-constant', '-std=gnu++11', '-fdata-sections', '-ffunction-sections', '-fno-exceptions', '-fsigned-char', '-Wall', '-Wextra', '-Wpointer-arith', '-Wno-unused-parameter', '-Wno-missing-field-initializers', '-Wno-reorder', '-Wno-redundant-decls', '-Wno-unknown-pragmas', '-Wno-expansion-to-defined', '-Werror=cast-align', '-Werror=attributes', '-Werror=format-security', '-Werror=format-extra-args', '-Werror=enum-compare', '-Werror=format', '-Werror=array-bounds', '-Werror=uninitialized', '-Werror=init-self', '-Werror=narrowing', '-Werror=return-type', '-Werror=switch', '-Werror=sign-compare', '-Werror=type-limits', '-Werror=undef', '-Werror=unused-result', '-Werror=shadow', '-Werror=unused-value', '-Werror=unused-variable', '-Werror=delete-non-virtual-dtor', '-Wfatal-errors', '-Wno-trigraphs', '-Werror=parentheses', '-DARDUPILOT_BUILD', '-Wuninitialized', '-Warray-bounds', '-Wno-format-contains-nul', '-Werror=unused-but-set-variable', '-Werror=suggest-override', '-Werror=implicit-fallthrough', '-Werror=maybe-uninitialized', '-Werror=duplicated-cond', '-Werror=sizeof-pointer-div', '-g', '-O0', '-D__AP_LINE__=__LINE__', '-DCANARD_64_BIT=1', '-Werror=float-equal', '-Werror=missing-declarations', '-DHAL_HAVE_AP_ROMFS_EMBEDDED_H', '-MMD', '-include', 'ap_config.h']
CXXFLAGS_MACBUNDLE = ['-fPIC']
CXXFLAGS_cxxshlib = ['-fPIC']
CXXLNK_SRC_F = []
CXXLNK_TGT_F = ['-o']
CXX_NAME = 'gcc'
CXX_SRC_F = []
CXX_TGT_F = ['-c', '-o']
DC_DSDL_COMPILER = '/home/svrt_31/ardusub/ardupilot/modules/DroneCAN/dronecan_dsdlc/dronecan_dsdlc.py'
DC_DSDL_COMPILER_DIR = '/home/svrt_31/ardusub/ardupilot/modules/DroneCAN/dronecan_dsdlc'
DEBUG = True
DEBUG_SYMBOLS = False
DEFINES = ['SKETCHBOOK="/home/svrt_31/ardusub/ardupilot"', 'AP_BARO_PROBE_EXTERNAL_I2C_BUSES=1', 'AP_CUSTOMCONTROL_ENABLED=1', 'AP_DDS_ENABLED=0', 'AP_SCRIPTING_CHECKS=1', 'CANARD_ALLOCATE_SEM=1', 'CANARD_ENABLE_ASSERTS=1', 'CANARD_ENABLE_CANFD=1', 'CANARD_ENABLE_DEADLINE=1', 'CANARD_IFACE_ALL=3', 'CANARD_MULTI_IFACE=1', 'CONFIG_HAL_BOARD=HAL_BOARD_SITL', 'CONFIG_HAL_BOARD_SUBTYPE=HAL_BOARD_SUBTYPE_NONE', 'DRONECAN_CXX_WRAPPERS=1', 'ENABLE_HEAP=1', 'ENABLE_ONVIF=0', 'HAL_DEBUG_BUILD=1', 'LUA_32BITS=1', 'USE_USER_HELPERS=1']
DEFINES_ST = '-D%s'
DEFINE_COMMENTS = {'WAF_BUILD': '', 'PYTHONDIR': '', 'PYTHONARCHDIR': '', '__STDC_FORMAT_MACROS': '', 'AP_SIM_ENABLED': '', 'HAL_WITH_SPI': '', 'HAL_WITH_RAMTRON': '', 'AP_GENERATOR_RICHENPOWER_ENABLED': '', 'AP_OPENDRONEID_ENABLED': '', 'AP_SIGNED_FIRMWARE': '', 'AP_NOTIFY_LP5562_BUS': '', 'AP_NOTIFY_LP5562_ADDR': '', 'HAL_NUM_CAN_IFACES': '', 'HAL_CAN_WITH_SOCKETCAN': '', 'HAVE_FEENABLEEXCEPT': '', 'HAVE_CMATH_ISFINITE': '', 'HAVE_CMATH_ISINF': '', 'HAVE_CMATH_ISNAN': '', 'NEED_CMATH_ISFINITE_STD_NAMESPACE': '', 'NEED_CMATH_ISINF_STD_NAMESPACE': '', 'NEED_CMATH_ISNAN_STD_NAMESPACE': '', 'HAVE_ENDIAN_H': '', 'HAVE_BYTESWAP_H': '', 'HAVE_MEMRCHR': '', '_GNU_SOURCE': ''}
DEST_BINFMT = 'elf'
DEST_CPU = 'x86_64'
DEST_OS = 'linux'
DOUBLE_PRECISION_LIBRARIES = {'AP_HAL_SITL': True, 'SITL': True}
DOUBLE_PRECISION_SOURCES = {'AP_GPS': ['AP_GPS_SBF.cpp']}
ENABLE_ASSERTS = False
ENABLE_CUSTOM_CONTROLLER = True
ENABLE_DDS = False
ENABLE_GCCDEPS = ['c', 'cxx']
ENABLE_HEADER_CHECKS = False
ENABLE_MALLOC_GUARD = False
ENABLE_ONVIF = False
ENABLE_STATS = False
FORCE32BIT = False
GIT = ['/usr/bin/git']
GIT_SUBMODULES = ['gtest', 'mavlink']
HAS_GTEST = True
HAVE_BYTESWAP_H = 1
HAVE_CMATH_ISFINITE = 1
HAVE_CMATH_ISINF = 1
HAVE_CMATH_ISNAN = 1
HAVE_ENDIAN_H = 1
HAVE_FEENABLEEXCEPT = 1
HAVE_MEMRCHR = 1
HWDEF_EXTRA = None
INCLUDES = ['/home/svrt_31/ardusub/ardupilot/libraries/', '/home/svrt_31/ardusub/ardupilot/libraries/AP_Common/missing']
LIB = ['m']
LIBDIR = '/usr/lib'
LIBPATH_ST = '-L%s'
LIB_ST = '-l%s'
LINKFLAGS = ['-fno-exceptions', '-Wl,--gc-sections', '-pthread']
LINKFLAGS_MACBUNDLE = ['-bundle', '-undefined', 'dynamic_lookup']
LINKFLAGS_cshlib = ['-shared']
LINKFLAGS_cstlib = ['-Wl,-Bstatic']
LINKFLAGS_cxxshlib = ['-shared']
LINKFLAGS_cxxstlib = ['-Wl,-Bstatic']
LINK_CC = ['/usr/bin/gcc']
LINK_CXX = ['/usr/bin/g++']
MAVLINK_DIR = '/home/svrt_31/ardusub/ardupilot/modules/mavlink'
NEED_CMATH_ISFINITE_STD_NAMESPACE = 1
NEED_CMATH_ISINF_STD_NAMESPACE = 1
NEED_CMATH_ISNAN_STD_NAMESPACE = 1
OPTIONS = {'colors': 'auto', 'jobs': 16, 'keep': 0, 'verbose': 0, 'zones': '', 'profile': 0, 'pdb': 0, 'whelp': 0, 'out': '', 'top': '', 'no_lock_in_run': '', 'no_lock_in_out': '', 'no_lock_in_top': '', 'prefix': '/usr', 'bindir': None, 'libdir': None, 'progress_bar': 0, 'targets': '', 'files': '', 'destdir': '', 'force': False, 'distcheck_args': None, 'check_cxx_compiler': None, 'check_c_compiler': None, 'no_tests': False, 'all_tests': False, 'clear_failed_tests': False, 'testcmd': False, 'dump_test_scripts': False, 'pyc': 1, 'pyo': 1, 'nopycache': None, 'python': None, 'pythondir': None, 'pythonarchdir': None, 'program_group': [], 'upload': None, 'upload_port': None, 'upload_force': None, 'check_verbose': None, 'define': None, 'clean_all_sigs': None, 'asan': None, 'ubsan': None, 'ubsan_abort': None, 'summary_all': None, 'board': 'sitl', 'debug': True, 'debug_symbols': False, 'disable_watchdog': False, 'coverage': False, 'Werror': None, 'disable_Werror': None, 'toolchain': None, 'disable_gccdeps': False, 'enable_asserts': False, 'save_temps': False, 'enable_malloc_guard': False, 'enable_stats': False, 'bootloader': False, 'signed_fw': False, 'private_key': None, 'autoconfig': True, 'submodule_update': True, 'enable_header_checks': False, 'default_parameters': None, 'enable_math_check_indexes': False, 'disable_scripting': False, 'enable_scripting': False, 'no_gcs': False, 'scripting_checks': True, 'enable_onvif': False, 'scripting_docs': False, 'enable_opendroneid': False, 'enable_check_firmware': False, 'enable_custom_controller': False, 'enable_gps_logging': False, 'enable_dds': None, 'enable_dronecan_tests': False, 'apstatedir': '', 'rsync_dest': '', 'enable_benchmarks': False, 'enable_lttng': False, 'disable_libiio': False, 'disable_tests': False, 'enable_sfml': False, 'enable_sfml_joystick': False, 'enable_sfml_audio': False, 'osd': False, 'osd_fonts': False, 'sitl_osd': False, 'sitl_rgbled': False, 'force_32bit': False, 'build_dates': False, 'sitl_flash_storage': False, 'disable_ekf2': False, 'disable_ekf3': False, 'ekf_double': False, 'ekf_single': False, 'static': False, 'postype_single': False, 'consistent_builds': False, 'extra_hwdef': None, 'assert_cc_version': None, 'num_aux_imus': 0, 'board_start_time': 0}
PREFIX = '/usr'
PYC = 1
PYFLAGS = ''
PYFLAGS_OPT = '-O'
PYO = 1
PYTAG = 'cpython-38'
PYTHON = ['/usr/bin/python']
PYTHONARCHDIR = '/usr/lib/python3.8/site-packages'
PYTHONDIR = '/usr/lib/python3.8/site-packages'
PYTHON_VERSION = '3.8'
ROMFS_FILES = [('models/Callisto.json', 'Tools/autotest/models/Callisto.json'), ('models/xplane_plane.json', 'Tools/autotest/models/xplane_plane.json'), ('models/xplane_heli.json', 'Tools/autotest/models/xplane_heli.json'), ('models/plane.parm', 'Tools/autotest/models/plane.parm'), ('models/plane-3d.parm', 'Tools/autotest/models/plane-3d.parm'), ('locations.txt', 'Tools/autotest/locations.txt')]
RPATH_ST = '-Wl,-rpath,%s'
RSYNC = ['/usr/bin/rsync']
SAVE_TEMPS = False
SHLIB_MARKER = '-Wl,-Bdynamic'
SIZE = ['/usr/bin/size']
SONAME_ST = '-Wl,-h,%s'
SRCROOT = '/home/svrt_31/ardusub/ardupilot'
STLIBPATH_ST = '-L%s'
STLIB_MARKER = '-Wl,-Bstatic'
STLIB_ST = '-l%s'
SUBMODULE_UPDATE = True
TOOLCHAIN = 'native'
cfg_files = ['/home/svrt_31/ardusub/ardupilot/build/sitl/ap_config.h']
cprogram_PATTERN = '%s'
cshlib_PATTERN = 'lib%s.so'
cstlib_PATTERN = 'lib%s.a'
cxxprogram_PATTERN = '%s'
cxxshlib_PATTERN = 'lib%s.so'
cxxstlib_PATTERN = 'lib%s.a'
define_key = []
macbundle_PATTERN = '%s.bundle'
