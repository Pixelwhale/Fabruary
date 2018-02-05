//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.10
// 内容　：Contentを読み込むクラス
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

		///<summary>初期化処理</summary>
		void Initialize();
		///<summary>Memory上のTextureを解放</summary>
		void Release();

#pragma region Model関連

		///<summary>Modelを読み込む</summary>
		///<param name="fileName">Asset名</param>
		///<param name="fileExtention">拡張子</param>
		///<param name="path">パス</param>
		void LoadModel(std::string file_name, std::string file_extention, std::string path = "./Content/Model/");

		///<summary>Textureのハンドルを取得</summary>
		///<param name="model_name">Textureの名前</param>
		///<returns>Model Handle</returns>
		int ModelHandle(std::string model_name);

#pragma endregion

#pragma region Texture関連

		///<summary>Textureを読み込む</summary>
		///<param name="fileName">Asset名</param>
		///<param name="fileExtention">拡張子</param>
		///<param name="path">パス</param>
		void LoadTexture(std::string file_name, std::string file_extention, std::string path = "./Content/Texture/");

		///<summary>Textureを読み込む</summary>
		///<param name="file_name">Asset名</param>
		///<param name="file_extention">拡張子</param>
		///<param name="total">総枚数</param>
		///<param name="x_count">横の枚数</param>
		///<param name="y_count">縦の枚数</param>
		///<param name="x_size">横サイズ</param>
		///<param name="y_size">縦サイズ</param>
		///<param name="path">パス</param>
		void LoadTexture(
			std::string file_name, std::string file_extention,
			int total, int x_count, int y_count, int x_size, int y_size,
			std::string path = "./Content/Texture/");

		///<summary>Textureのハンドルを取得</summary>
		///<param name="texture_name">Textureの名前</param>
		///<returns>Texture Handle</returns>
		int TextureHandle(std::string texture_name);

		///<summary>Textureのハンドルを取得</summary>
		///<param name="texture_name">Asset名</param>
		///<param name="motion_index">何枚目</param>
		int MotionHandle(std::string texture_name, int motion_index);

#pragma endregion

#pragma region Font関連

		///<summary>Fontを読み込む</summary>
		///<param name="font_name">Fontの名前</param>
		///<param name="size">大きさ</param>
		///<param name="thickness">太さ（0～9）</param>
		void LoadFont(std::string font_name, int size, int thickness);

		///<summary>Fontのハンドルを取得</summary>
		///<param name="font_name">Fontの名前</param>
		int FontHandle(std::string font_name);

#pragma endregion

#pragma region Shader関連
		///<summary>Shaderを読み込む</summary>
		///<param name="fileName">Asset名</param>
		///<param name="fileExtention">拡張子</param>
		///<param name="path">パス</param>
		void LoadShaderPixel(std::string file_name, std::string file_extention, std::string path = "./Content/Shader/");

		///<summary>Shaderのハンドルを取得</summary>
		///<param name="shader_name">Shaderの名前</param>
		///<returns>Shader Handle</returns>
		int PixelShaderHandle(std::string shader_name);
#pragma endregion

#pragma region Sprite Studio関連

		void LoadSSFile(std::string file_name, std::string path = "./Content/SpriteStudio/");

#pragma endregion

#pragma region Sound関連

		///<summary>BGMを読み込む</summary>
		///<param name="fileName">Asset名</param>
		///<param name="fileExtention">拡張子</param>
		///<param name="path">パス</param>
		void LoadBGM(std::string file_name, std::string file_extention, std::string path = "./Content/BGM/");
		///<summary>SEを読み込む</summary>
		///<param name="fileName">Asset名</param>
		///<param name="fileExtention">拡張子</param>
		///<param name="path">パス</param>
		void LoadSE(std::string file_name, std::string file_extention, std::string path = "./Content/SE/");
		///<summary>BGMのハンドルを取得</summary>
		///<param name="texture_name">BGMの名前</param>
		///<returns>BGM Handle</returns>
		int BGMHandle(std::string bgm_name);
		///<summary>SEのハンドルを取得</summary>
		///<param name="texture_name">SEの名前</param>
		///<returns>SE Handle</returns>
		int SEHandle(std::string se_name);

#pragma endregion

	private:
		std::map<std::string, int> m_models;			//モデルのハンドル
		std::map<std::string, int> m_textures;			//テクスチャのハンドル
		std::map<std::string, int*> m_motion;			//Animated Texture
		std::map<std::string, int> m_font;				//Font
		std::map<std::string, int> m_pixel_shader;		//Pixel Shader
		std::map<std::string, int> m_bgms;				//BGM
		std::map<std::string, int> m_sound_effects;		//SE

		ss::ResourceManager* m_resource_manager;		//SpriteStudioのresource Manager
	};
}