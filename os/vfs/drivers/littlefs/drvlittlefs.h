/*
    ChibiOS - Copyright (C) 2006..2024 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file        drvlittlefs.h
 * @brief       Generated VFS LittleFS Driver header.
 * @note        This is a generated file, do not edit directly.
 *
 * @addtogroup  DRVLITTLEFS
 * @{
 */

#ifndef DRVLITTLEFS_H
#define DRVLITTLEFS_H

#if (VFS_CFG_ENABLE_DRV_LITTLEFS == TRUE) || defined(__DOXYGEN__)

#include "oop_sequential_stream.h"
#include "lfs.h"

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief       Maximum number of LittleFS file systems mounted.
 */
#if !defined(DRV_CFG_LITTLEFS_FS_NUM) || defined(__DOXYGEN__)
#define DRV_CFG_LITTLEFS_FS_NUM             1
#endif

/**
 * @brief       Number of directory nodes pre-allocated in the pool.
 */
#if !defined(DRV_CFG_LITTLEFS_DIR_NODES_NUM) || defined(__DOXYGEN__)
#define DRV_CFG_LITTLEFS_DIR_NODES_NUM      2
#endif

/**
 * @brief       Number of file nodes pre-allocated in the pool.
 */
#if !defined(DRV_CFG_LITTLEFS_FILE_NODES_NUM) || defined(__DOXYGEN__)
#define DRV_CFG_LITTLEFS_FILE_NODES_NUM     2
#endif

/**
 * @brief       Number of info nodes pre-allocated in the pool.
 */
#if !defined(DRV_CFG_LITTLEFS_INFO_NODES_NUM) || defined(__DOXYGEN__)
#define DRV_CFG_LITTLEFS_INFO_NODES_NUM     1
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* Checks on DRV_CFG_LITTLEFS_FS_NUM configuration.*/
#if DRV_CFG_LITTLEFS_FS_NUM < 1
#error "invalid DRV_CFG_LITTLEFS_FS_NUM value"
#endif

/* Checks on DRV_CFG_LITTLEFS_DIR_NODES_NUM configuration.*/
#if DRV_CFG_LITTLEFS_DIR_NODES_NUM < 2
#error "invalid DRV_CFG_LITTLEFS_DIR_NODES_NUM value"
#endif

/* Checks on DRV_CFG_LITTLEFS_FILE_NODES_NUM configuration.*/
#if DRV_CFG_LITTLEFS_FILE_NODES_NUM < 1
#error "invalid DRV_CFG_LITTLEFS_FILE_NODES_NUM value"
#endif

/* Checks on DRV_CFG_LITTLEFS_INFO_NODES_NUM configuration.*/
#if DRV_CFG_LITTLEFS_INFO_NODES_NUM < 1
#error "invalid DRV_CFG_LITTLEFS_INFO_NODES_NUM value"
#endif

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/**
 * @class       vfs_littlefs_driver_c
 * @extends     base_object_c, vfs_driver_c.
 *
 *
 * @name        Class @p vfs_littlefs_driver_c structures
 * @{
 */

/**
 * @brief       Type of a VFS LittleFS driver class.
 */
typedef struct vfs_littlefs_driver vfs_littlefs_driver_c;

/**
 * @brief       Class @p vfs_littlefs_driver_c virtual methods table.
 */
struct vfs_littlefs_driver_vmt {
  /* From base_object_c.*/
  void (*dispose)(void *ip);
  /* From vfs_driver_c.*/
  msg_t (*setcwd)(void *ip, const char *path);
  msg_t (*getcwd)(void *ip, char *buf, size_t size);
  msg_t (*stat)(void *ip, const char *path, vfs_stat_t *sp);
  msg_t (*opendir)(void *ip, const char *path, vfs_directory_node_c **vdnpp);
  msg_t (*openfile)(void *ip, const char *path, int flags, vfs_file_node_c **vfnpp);
  msg_t (*unlink)(void *ip, const char *path);
  msg_t (*rename)(void *ip, const char *oldpath, const char *newpath);
  msg_t (*mkdir)(void *ip, const char *path, vfs_mode_t mode);
  msg_t (*rmdir)(void *ip, const char *path);
  /* From vfs_littlefs_driver_c.*/
};

/**
 * @brief       Structure representing a VFS LittleFS driver class.
 */
struct vfs_littlefs_driver {
  /**
   * @brief       Virtual Methods Table.
   */
  const struct vfs_littlefs_driver_vmt  *vmt;
  /**
   * @brief       File system object.
   */
  lfs_t                                 lfs;
  /**
   * @brief       File system volume name.
   */
  const char                            *name;
  /**
   * @brief       File system directory node.
   */
  struct vfs_littlefs_dir_node          *cwd;
  /**
   * @brief       File system current directory path.
   */
  char                                  path_cwd[LFS_NAME_MAX];
  /**
   * @brief       Path name scratch pad.
   */
  char                                  scratch[LFS_NAME_MAX];
};
/** @} */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

extern struct vfs_littlefs_driver_static_struct vfs_littlefs_driver_static;

#ifdef __cplusplus
extern "C" {
#endif
  /* Methods of vfs_littlefs_driver_c.*/
  void *__lfsdrv_objinit_impl(void *ip, const void *vmt);
  void __lfsdrv_dispose_impl(void *ip);
  msg_t __lfsdrv_setcwd_impl(void *ip, const char *path);
  msg_t __lfsdrv_getcwd_impl(void *ip, char *buf, size_t size);
  msg_t __lfsdrv_stat_impl(void *ip, const char *path, vfs_stat_t *sp);
  msg_t __lfsdrv_opendir_impl(void *ip, const char *path,
                              vfs_directory_node_c **vdnpp);
  msg_t __lfsdrv_openfile_impl(void *ip, const char *path, int flags,
                               vfs_file_node_c **vfnpp);
  msg_t __lfsdrv_unlink_impl(void *ip, const char *path);
  msg_t __lfsdrv_rename_impl(void *ip, const char *oldpath,
                             const char *newpath);
  msg_t __lfsdrv_mkdir_impl(void *ip, const char *path, vfs_mode_t mode);
  msg_t __lfsdrv_rmdir_impl(void *ip, const char *path);
  /* Regular functions.*/
  void __drv_littlefs_init(void);
  msg_t lfsdrvMount(const char *name, const struct lfs_config *cfgp,
                                                vfs_littlefs_driver_c **obj);
  msg_t lfsdrvUnmount(const char *name);
  const char *lfsdrvGetName(vfs_littlefs_driver_c *drvp);
#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/**
 * @name        Default constructor of vfs_littlefs_driver_c
 * @{
 */
/**
 * @memberof    vfs_littlefs_driver_c
 *
 * @brief       Default initialization function of @p vfs_littlefs_driver_c.
 *
 * @param[out]    self          Pointer to a @p vfs_littlefs_driver_c instance
 *                              to be initialized.
 * @param[in]     cfgp          Pointer to @p lfs_config configuration.
 * @return                      Pointer to the initialized object.
 * @retval                      NULL if initialisation failed.
 *
 * @objinit
 */
CC_FORCE_INLINE
static inline vfs_littlefs_driver_c *lfsdrvObjectInit(vfs_littlefs_driver_c *self,
                                      const struct lfs_config *cfgp) {
  extern const struct vfs_littlefs_driver_vmt __vfs_littlefs_driver_vmt;
  vfs_littlefs_driver_c *obj = __lfsdrv_objinit_impl(self,
                                        &__vfs_littlefs_driver_vmt);

  /* Mount the drive using the supplied configuration.*/
  if (lfs_mount(&obj->lfs, cfgp) == LFS_ERR_OK) {

    /* Check drive is functional. Open root directory as current.*/
    if (__lfsdrv_setcwd_impl(self, "/") == CH_RET_SUCCESS) {
      return obj;
    }
    (void) lfs_unmount(&self->lfs);
  }

  return NULL;
}
/** @} */

#endif /* VFS_CFG_ENABLE_DRV_LITTLEFS == TRUE */

#endif /* DRVLITTLEFS_H */

/** @} */