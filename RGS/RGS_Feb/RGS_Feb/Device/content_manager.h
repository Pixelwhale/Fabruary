//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.10
// ���e�@�FContent��ǂݍ��ރN���X
//-------------------------------------------------------
#pragma once
#include <map>
#include <ssbpLib\SS5Player.h>

namespace Device
{
	class ContentManager
	{
	public:
		ContentManager();
		ContentManager(const ContentManager&);
		~ContentManager();

		///<summary>����������</summary>
		void Initialize();
		///<summary>Memory���Texture�����</summary>
		void Release();

#pragma region Model�֘A

		///<summary>Model��ǂݍ���</summary>
		///<param name="fileName">Asset��</param>
		///<param name="fileExtention">�g���q</param>
		///<param name="path">�p�X</param>
		void LoadModel(std::string file_name, std::string file_extention, std::string path = "./Content/Model/");

		///<summary>Texture�̃n���h�����擾</summary>
		///<param name="model_name">Texture�̖��O</param>
		///<returns>Model Handle</returns>
		int ModelHandle(std::string model_name);

#pragma endregion

#pragma region Texture�֘A

		///<summary>Texture��ǂݍ���</summary>
		///<param name="fileName">Asset��</param>
		///<param name="fileExtention">�g���q</param>
		///<param name="path">�p�X</param>
		void LoadTexture(std::string file_name, std::string file_extention, std::string path = "./Content/Texture/");

		///<summary>Texture��ǂݍ���</summary>
		///<param name="file_name">Asset��</param>
		///<param name="file_extention">�g���q</param>
		///<param name="total">������</param>
		///<param name="x_count">���̖���</param>
		///<param name="y_count">�c�̖���</param>
		///<param name="x_size">���T�C�Y</param>
		///<param name="y_size">�c�T�C�Y</param>
		///<param name="path">�p�X</param>
		void LoadTexture(
			std::string file_name, std::string file_extention,
			int total, int x_count, int y_count, int x_size, int y_size,
			std::string path = "./Content/Texture/");

		///<summary>Texture�̃n���h�����擾</summary>
		///<param name="texture_name">Texture�̖��O</param>
		///<returns>Texture Handle</returns>
		int TextureHandle(std::string texture_name);

		///<summary>Texture�̃n���h�����擾</summary>
		///<param name="texture_name">Asset��</param>
		///<param name="motion_index">������</param>
		int MotionHandle(std::string texture_name, int motion_index);

#pragma endregion

#pragma region Font�֘A

		///<summary>Font��ǂݍ���</summary>
		///<param name="font_name">Font�̖��O</param>
		///<param name="size">�傫��</param>
		///<param name="thickness">�����i0�`9�j</param>
		void LoadFont(std::string font_name, int size, int thickness);

		///<summary>Font�̃n���h�����擾</summary>
		///<param name="font_name">Font�̖��O</param>
		int FontHandle(std::string font_name);

#pragma endregion

#pragma region Shader�֘A
		///<summary>Shader��ǂݍ���</summary>
		///<param name="fileName">Asset��</param>
		///<param name="fileExtention">�g���q</param>
		///<param name="path">�p�X</param>
		void LoadShaderPixel(std::string file_name, std::string file_extention, std::string path = "./Content/Shader/");

		///<summary>Shader�̃n���h�����擾</summary>
		///<param name="shader_name">Shader�̖��O</param>
		///<returns>Shader Handle</returns>
		int PixelShaderHandle(std::string shader_name);
#pragma endregion

#pragma region Sprite Studio�֘A

		void LoadSSFile(std::string file_name, std::string path = "./Content/SpriteStudio/");

#pragma endregion

#pragma region Sound�֘A

		///<summary>BGM��ǂݍ���</summary>
		///<param name="fileName">Asset��</param>
		///<param name="fileExtention">�g���q</param>
		///<param name="path">�p�X</param>
		void LoadBGM(std::string file_name, std::string file_extention, std::string path = "./Content/BGM/");
		///<summary>SE��ǂݍ���</summary>
		///<param name="fileName">Asset��</param>
		///<param name="fileExtention">�g���q</param>
		///<param name="path">�p�X</param>
		void LoadSE(std::string file_name, std::string file_extention, std::string path = "./Content/SE/");
		///<summary>BGM�̃n���h�����擾</summary>
		///<param name="texture_name">BGM�̖��O</param>
		///<returns>BGM Handle</returns>
		int BGMHandle(std::string bgm_name);
		///<summary>SE�̃n���h�����擾</summary>
		///<param name="texture_name">SE�̖��O</param>
		///<returns>SE Handle</returns>
		int SEHandle(std::string se_name);

#pragma endregion

	private:
		std::map<std::string, int> m_models;			//���f���̃n���h��
		std::map<std::string, int> m_textures;			//�e�N�X�`���̃n���h��
		std::map<std::string, int*> m_motion;			//Animated Texture
		std::map<std::string, int> m_font;				//Font
		std::map<std::string, int> m_pixel_shader;		//Pixel Shader
		std::map<std::string, int> m_bgms;				//BGM
		std::map<std::string, int> m_sound_effects;		//SE

		ss::ResourceManager* m_resource_manager;		//SpriteStudio��resource Manager
	};
}