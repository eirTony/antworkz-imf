#ifndef EMPTY_GLOBAL_H
#define EMPTY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(VAR_LIBRARY)
#  define VARSHARED_EXPORT Q_DECL_EXPORT
#else
#  define VARSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // EMPTY_GLOBAL_H
