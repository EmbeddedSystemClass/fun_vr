

#ifndef avi_h
#define avi_h
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

typedef enum avi_audio_codec
{
    AVI_CODEC_AUDIO32       =  0x5541,
    AVI_CODEC_SN_IMA_ADPCM  =  0x04D4,
    AVI_CODEC_WINDOWS_PCM   =  0x5601,
    AVI_CODEC_IMA_ADPCM     =  0x5600,

} savi_audio_codec_t;



/**
 *  frame info
 */
typedef struct avi_frm_info
{
    long        header_offset;
    int         header_length;

    long        curr_frm_offset_in_idx_table;
    long        next_frm_offset_in_idx_table;

} avi_frm_info_t;

struct avi_demux_ctrl;

/**
 *  \brief CB_FRAME_INFO    callback function when demuxes a frame
 *
 *  \param [in] pCtrl           pass control info from savi_demux()
 *  \param [in] pFrm_info       info of a frame
 *  \return Return              0: ok, other: fail
 *
 *  \details
 */
typedef int (*CB_AVI_FRAME_INFO)(struct avi_demux_ctrl *pCtrl, avi_frm_info_t *pFrm_info);

/**
 *  demux controlling setting
 */
typedef struct avi_demux_ctrl
{
    int                     frame_idx;
    CB_AVI_FRAME_INFO           cb_frame_info;


    /**
     *  attach user data
     */
    void    *pTunnel_info;

} avi_demux_ctrl_t;



typedef struct avi_header
{
    uint32_t        tag;

    uint32_t        raw_data_offset_vid;
    uint32_t        frame_rate;
    uint32_t        frame_max_num;
	
	uint32_t		jpeg_width;
	uint32_t		jpeg_height;

    uint32_t        adu_list_offset;

    uint32_t        idx_table_offset_vid;
    uint32_t        idx_table_size_vid;

	uint32_t		audioexist;
	uint32_t		is_init_jpeg_header;
} avi_header_t;


/**
 *  \brief  Parse header of a SAVI file
 *
 *  \param [in] pBuf        stream of a savi file
 *  \param [in] buf_size    buffer size
 *  \param [in] pHdr        report result after parsing
 *  \return                 0: ok, other: fail
 *
 *  \details
 */
int
avi_parse_header(
    uint32_t        *pBuf,
    uint32_t        buf_size,
    avi_header_t   *pHeader);

/**
 *  \brief  Only demux video frame
 *
 *  \param [in] pHdr            header info which is generated by savi_parse_header()
 *  \param [in] pCtrl_info      controlling setting for demuxing
 *  \return                     0: ok, other: fail
 *
 *  \details
 */
int
avi_demux_video(
    avi_header_t       *pHdr,
    avi_demux_ctrl_t   *pCtrl_info);




#ifdef __cplusplus
extern "C" {
#endif
#endif
